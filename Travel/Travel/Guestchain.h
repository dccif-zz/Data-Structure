#pragma once
#include<iostream>

using namespace std;

//游客的单链表
class guestchain {
public:
	int guestId;
	char* name;
	guestchain *next;

	//构造函数
	//guestchain(int id,char* thename):guestId(id),name(thename),next(NULL){}
	guestchain(int id) :guestId(id), name("默认"), next(NULL) {}

	//方法
	void printall(guestchain *chpoint);
	int insertchain(int id, guestchain *chainpoint);
	guestchain* deletechain(int id, guestchain *chainpoint);
	int countNum(guestchain *chain);
	int writeTotree(int Num);
};

//单链表输出
void guestchain::printall(guestchain *chpoint)
{
	while (NULL != chpoint->next) {
		cout << chpoint->guestId << endl;
		chpoint = chpoint->next;
	}
	cout << chpoint->guestId << endl;
}

//单链表插入
int guestchain::insertchain(int id, guestchain *chain)
{
	while (NULL != chain->next) {
		chain  = chain ->next;
	}
	chain->next = new guestchain(id);
	return 0;
}

//单链表删除
guestchain* guestchain::deletechain(int id, guestchain *chpoint)
{
	guestchain *prtbef = chpoint;
	guestchain *prtcul = chpoint;
	if (chpoint->guestId == id) {
		prtbef = chpoint;
		chpoint = chpoint->next;
		delete prtbef;
		return chpoint;
	}
	while (prtcul->guestId !=id && prtcul->next !=NULL)
	{
		prtbef = prtcul;
		prtcul = prtcul->next;
	}
	if (prtcul->guestId == id) {
		prtbef->next = prtcul->next;
		delete prtcul;
	}
	return chpoint;
}

//单链表计数
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



