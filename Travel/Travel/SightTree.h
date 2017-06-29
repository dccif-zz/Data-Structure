#pragma once
#include"Guestchain.h"
using namespace std;

//景点的二叉排序树
class sightTree {
public:
	sightTree *lchild;
	sightTree *rchild;
	int sightID;
	guestchain *chain;//单链表指针
	int flow;
	int pv;
	//构造函数
	sightTree(int id) :sightID(id), lchild(NULL), rchild(NULL), chain(NULL), flow(0), pv(0) {}

	//方法
	void insertnode(int newid);
	void deletenode(int newid);

	//遍历
	void inorder(sightTree *tree);
	void preorder(sightTree *tree);
};

//二叉排序树插入
void sightTree::insertnode(int newid)
{
	if (newid && lchild) {
		lchild->insertnode(newid);
	}
	else if (newid < sightID && !lchild) {
		lchild = new sightTree(newid);
	}
	else if (newid > sightID && rchild)
	{
		rchild->insertnode(newid);
	}
	else if (newid > sightID && !rchild)
	{
		rchild = new sightTree(newid);
	}
}

//中序遍历
void sightTree::inorder(sightTree *tree)
{
	if (tree != NULL) {
		inorder(tree->lchild);
		cout << tree->sightID << endl;
		inorder(tree->rchild);
	}
}

//前序遍历
void sightTree::preorder(sightTree *tree)
{
	if (tree != NULL) {
		cout << tree->sightID << endl;
		inorder(tree->lchild);
		inorder(tree->rchild);
	}
}

