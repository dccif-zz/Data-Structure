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
	int countNum(guestchain *chain);
	int writeTotree(int Num);
};

//单链表输出
void guestchain::printall(guestchain *chpoint)
{
	while (NULL != chpoint->next) {
		cout << chpoint->guestId << endl;
	}
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

