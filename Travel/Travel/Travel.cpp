#include<iostream>
#include"Guestchain.h"
#include"SightTree.h"

using namespace std;

//测试函数
int main() {
	guestchain *chainpoint;
	guestchain Myguest(8);
	chainpoint = &Myguest;
	//Myguest.insertchain(2);
	/*Myguest.insertchain(5, chainpoint);
	Myguest.insertchain(8, chainpoint);
	Myguest.insertchain(9, chainpoint);
	Myguest.printall(chainpoint);
	Myguest.countNum(chainpoint);
	Myguest.deletechain(9, chainpoint);
	Myguest.printall(chainpoint);
	Myguest.countNum(chainpoint);*/

	sightTree *Treepoint;
	sightTree Mysight(5);
	Treepoint = &Mysight;
	Mysight.chain = chainpoint;
	Mysight.chain->printall(chainpoint);
	Mysight.insertnode(4,Treepoint);
	Mysight.insertnode(9,Treepoint);
	Mysight.insertnode(6, Treepoint);


	


	system("pause");
	return 0;
}