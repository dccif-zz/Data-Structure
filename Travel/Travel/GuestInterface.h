#pragma once
#include<iostream>
#include<random>
#include<string>
#include"Guestchain.h"

using namespace std;

class GuestUI {
public:
	int choiceNum;
	int guestRandomId;
	string guestname;
	guestchain* headpoint;

	GuestUI() {
		random_device rd;
		mt19937 gen = mt19937(rd());
		uniform_real_distribution<> dis(1, 100);
		guestRandomId = (int)dis(gen);
		headpoint = new guestchain(guestRandomId);
		cin >> guestname;
		headpoint->name = guestname;
		choiceNum = 0;
	}
	//·½·¨
	void choice();
};

void GuestUI::choice()
{
	cout << guestRandomId;
}