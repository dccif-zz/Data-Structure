#pragma once
#include<iostream>

using namespace std;

//�ο͵ĵ�����
class guestchain {
public:
	int guestId;
	char* name;
	guestchain *next;

	//���캯��
	//guestchain(int id,char* thename):guestId(id),name(thename),next(NULL){}
	guestchain(int id) :guestId(id), name("Ĭ��"), next(NULL) {}

	//����
	void printall(guestchain *chpoint);
	int insertchain(int id, guestchain *chainpoint);
	guestchain* deletechain(int id, guestchain *chainpoint);
	int countNum(guestchain *chain);
	int writeTotree(int Num);
};

//���������
//chpoint Ϊ������ָ��
void guestchain::printall(guestchain *chpoint)
{
	while (NULL != chpoint->next) {
		cout << chpoint->guestId << endl;
		chpoint = chpoint->next;
	}
	cout << chpoint->guestId << endl;
}

//���������
int guestchain::insertchain(int id, guestchain *chain)
{
	while (NULL != chain->next) {
		chain  = chain ->next;
	}
	chain->next = new guestchain(id);
	return 0;
}

//������ɾ��
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
	while (prtdel->guestId !=id && prtdel->next !=NULL)
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
int guestchain::countNum(guestchain *chpoint)
{
	int num = 1;
	while (NULL!= chpoint->next) {
		chpoint = chpoint->next;
		num++;
	}
	cout << num << endl;
	return num;
}



