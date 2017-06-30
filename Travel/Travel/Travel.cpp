#include<iostream>
#include"UI.h"
#include"Guestchain.h"
#include"GuestInterface.h"
#include"SightTree.h"
#include"AdministratorInterface.h"

using namespace std;




//测试函数
int main() {
	//guestchain *chainpoint, *opchainpoint;
	//guestchain Myguest(8);
	//chainpoint = &Myguest;			//单链表头指针
	//opchainpoint = &Myguest;		//单链表操作指针
	/*Myguest.insertchain(2, chainpoint);
	Myguest.insertchain(5, chainpoint);
	Myguest.insertchain(7, chainpoint);
	Myguest.insertchain(9, chainpoint);
	Myguest.printall(chainpoint);
	Myguest.countNum(chainpoint);
	Myguest.deletechain(9, chainpoint);
	Myguest.printall(chainpoint);
	Myguest.countNum(chainpoint);*/
	//Myguest.chainsearch(7, opchainpoint);


	/*sightTree *Treepoint;
	sightTree Mysight(45);
	Treepoint = &Mysight;
	Mysight.chain = chainpoint;
	Mysight.chain->printall(chainpoint);
	Mysight.insertnode(24, Treepoint);
	Mysight.insertnode(53, Treepoint);
	Mysight.insertnode(12, Treepoint);*/
	//Mysight.deletenode(24, Treepoint);

	TheInterface *myint = new TheInterface();
	myint->Login();

	system("pause");
	return 0;
}