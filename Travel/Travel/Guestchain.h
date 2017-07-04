#pragma once
#include<iostream>
#include<string>

using namespace std;

//�ο͵ĵ�����
class guestchain {
public:
	int guestId;
	string name;
	guestchain *next;

	//���캯��
	//guestchain(int id,char* thename):guestId(id),name(thename),next(NULL){}
	guestchain(int id, string itsname) :guestId(id), name(itsname), next(NULL) {}
	guestchain(int id) :guestId(id), name("Ĭ��"), next(NULL) {}

	//����
	void printall();
	int insertchain(int id, string itsname, guestchain *chainpoint);
	guestchain* deletechain(int id, guestchain *chainpoint);
	int countNum(guestchain *chain);
	guestchain* chainsearch(int id, guestchain *&chainpoint);
};

//���������
//chpoint Ϊ������ָ��
void guestchain::printall()
{
	guestchain* headpoint = this;
	if (headpoint == NULL) {
		return;
	}
	else
	{
		cout << "��ǰIDΪ��	" << "������" << endl;
		while (NULL != headpoint->next) {
			cout << headpoint->guestId << "	 	";
			cout << headpoint->name << endl;
			headpoint = headpoint->next;
		}
	}
	cout << headpoint->guestId << "		 ";
	cout << headpoint->name << "	" << endl;
}

//���������
int guestchain::insertchain(int id, string itsname, guestchain *chain)
{
	while (NULL != chain->next) {
		chain = chain->next;
	}
	chain->next = new guestchain(id, itsname);
	return 0;
}

//������ɾ��
//id Ҫɾ���Ľ��
//chpoint ������ָ��
//���� guestchainָ��
guestchain* guestchain::deletechain(int id, guestchain *chpoint)
{
	guestchain *prtbef = chpoint;			//ǰ��ָ��
	guestchain *prtdel = chpoint;			//ɾ��ָ��
	if (chpoint->guestId == id) {			//�����ͷ����ɾ��
		prtbef = chpoint;
		chpoint = chpoint->next;
		delete prtbef;
		return chpoint;
	}
	while (prtdel->guestId != id && prtdel->next != NULL)
	{
		prtbef = prtdel;
		prtdel = prtdel->next;
	}
	if (prtdel->guestId == id) {
		prtbef->next = prtdel->next;
		delete prtdel;
	}
	return chpoint;
}

//���������
//chpoint ������ָ��
int guestchain::countNum(guestchain *chpoint)
{
	int num = 1;
	while (NULL != chpoint->next) {
		chpoint = chpoint->next;
		num++;
	}
	cout << num << endl;
	return num;
}

//������Ĳ���
//id Ҫ����Ԫ��
//chainpoint ������ָ��
guestchain* guestchain::chainsearch(int id, guestchain *&chainpoint)
{
	guestchain *prtbef = chainpoint;		//ǰ��ָ��
	if (chainpoint->next == NULL) {
		if (chainpoint->guestId == id) {
			return prtbef;
		}
		else
		{
			return NULL;
		}
	}

	while (chainpoint->next != NULL)
	{
		prtbef = chainpoint;
		if (chainpoint->guestId == id) {
			return prtbef;
		}
		chainpoint = chainpoint->next;
	}
	//��������ûƥ�䵽���򷵻ؿ�ָ��
	if (chainpoint->guestId != id) {
		chainpoint = NULL;
		return chainpoint;
	}
	else
	{
		return chainpoint;
	}
}



