#pragma once
#include<iostream>
#include"Guestchain.h"
#include"GuestInterface.h"
#include"SightTree.h"
#include"AdministratorInterface.h"

using namespace std;

class TheInterface {
public:
	int sightChoice;
	int GuestChoice;
	int Temp;

	AdminUI* AdministratorInterface;
	GuestUI* GuestInterface;

	TheInterface() {}

	//方法
	void Login();
};


void TheInterface::Login() {
	int temp = 0;
	cout << "欢迎使用旅游管理系统，请选择身份：（1：管理员，2：游客）" << endl;
	cin >> temp;
	if (temp == 1) {
		//切换到管理员界面
		AdministratorInterface = new AdminUI;
	}
	else if (temp = 2)
	{
		//切换到游客界面
		GuestInterface = new GuestUI;
		GuestInterface->choice();
	}
}
