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

	//����
	void Login();
};


void TheInterface::Login() {
	int temp = 0;
	cout << "��ӭʹ�����ι���ϵͳ����ѡ����ݣ���1������Ա��2���οͣ�" << endl;
	cin >> temp;
	if (temp == 1) {
		//�л�������Ա����
		AdministratorInterface = new AdminUI;
	}
	else if (temp = 2)
	{
		//�л����οͽ���
		GuestInterface = new GuestUI;
		GuestInterface->choice();
	}
}
