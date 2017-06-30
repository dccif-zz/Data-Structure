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
	void insertnode(int newid,sightTree *root);
	int deletenode(int newid,sightTree *root);
	sightTree* search(int newid, sightTree *&root);

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
		else if(q->sightID > newid)
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



//二叉排序树插入
void sightTree::insertnode(int newid,sightTree *root)
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
		else if(root && newid > root->sightID)
			root->rchild = r;
	}
}

//二叉排序树的删除
int sightTree::deletenode(int newid,sightTree *p)
{
	sightTree *f,*q, *s;
	f = NULL;
	
	while (p && p->sightID  != newid)
	{
		f = p;
		if (p->sightID > newid) {
			p = p->lchild;
		}
		else
		{
			p = p->rchild;
		}
	}
	if (!p)
		return 0;
	if (p->lchild == NULL) 
	{
		if (f == NULL) {
			p = p->rchild;
		}
		else if(f->lchild ==p)
		{
			f->lchild = p->rchild;
		}
		else
		{
			f->rchild = p->rchild;
		}
		delete p;
	}
	else
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		if (q == p) {
			q->lchild = s->lchild;
		}
		else
		{
			q->rchild = s->lchild;
		}
		p->sightID = s->sightID;
		delete s;
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

