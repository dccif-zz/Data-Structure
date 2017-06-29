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
	Myguest.insertchain(5, chainpoint);
	Myguest.insertchain(8, chainpoint);
	Myguest.insertchain(9, chainpoint);
	Myguest.printall(chainpoint);
	Myguest.countNum(chainpoint);
	Myguest.deletechain(5, chainpoint);
	Myguest.printall(chainpoint);
	Myguest.countNum(chainpoint);

	sightTree *Treepoint;
	sightTree Mysight(5);
	Treepoint = &Mysight;
	Mysight.insertnode(4);
	Mysight.insertnode(6);
	Mysight.inorder(Treepoint);
	

	system("pause");
	return 0;
}