#pragma once
#include"Guestchain.h"
using namespace std;

//景点的二叉排序树
class sightTree {
public:
	int sightID;
	sightTree *lchild;
	sightTree *rchild;
	guestchain *chain;//单链表指针
	int flow;
	int pv;
	//构造函数
	sightTree(int id) :sightID(id), lchild(NULL), rchild(NULL), chain(NULL), flow(0), pv(0) {}
	sightTree() :lchild(NULL), rchild(NULL), chain(NULL), flow(0), pv(0) {}

	//方法
	void insertnode(int newid, sightTree *root);
	void deletenode(int newid, sightTree *&root);
	sightTree* search(int newid, sightTree *&root);
	sightTree* findMin(sightTree *&minpin);

	//遍历

	void inorder(sightTree *tree);
	void preorder(sightTree *tree);

};

//二叉排序树查找
sightTree * sightTree::search(int newid, sightTree *&root)
{
	sightTree *q = NULL;
	q = root;
	while (q)
	{
		root = q;
		if (q->sightID == newid) {
			return root;
		}
		else if (q->sightID > newid)
		{
			q = q->lchild;
		}
		else
		{
			q = q->rchild;
		}
	}
	return NULL;
}

sightTree * sightTree::findMin(sightTree *&minpin) {
	if (NULL != minpin) {
		while (NULL != minpin->lchild)
		{
			minpin = minpin->lchild;
		}
	}
	return minpin;
}

//二叉排序树插入
void sightTree::insertnode(int newid, sightTree *root)
{
	sightTree *q = root;
	if (search(newid, root) == NULL)
	{
		sightTree *r = new sightTree(newid);
		if (root == NULL) {
			root = r;
			return;
		}
		if (root&&newid < root->sightID)
			root->lchild = r;
		else if (root && newid > root->sightID)
			root->rchild = r;
	}
}

//二叉排序树的删除
void sightTree::deletenode(int newid, sightTree *&p)
{
	if (NULL == p) {
		return;
	}
	else
	{
		if (newid < p->sightID) {
			deletenode(newid, p->lchild);
		}
		else if (newid > p->sightID)
		{
			deletenode(newid, p->rchild);
		}
		else if (NULL != p->lchild && NULL != p->rchild) {
			p->sightID = findMin(p->rchild)->sightID;
			deletenode(p->sightID, p->rchild);
		}
		else
		{
			sightTree * oldnode = p;
			p = (NULL != p->lchild) ? p->lchild : p->rchild;
			delete oldnode;
		}
	}
}


//中序遍历
void sightTree::inorder(sightTree *tree)
{
	if (tree != NULL) {
		inorder(tree->lchild);
		cout << tree->sightID<<"	";
		tree->chain->printall();
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

