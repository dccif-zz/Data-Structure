#pragma once
#include"Guestchain.h"
using namespace std;

//����Ķ���������
class sightTree {
public:
	sightTree *lchild;
	sightTree *rchild;
	int sightID;
	guestchain *chain;//������ָ��
	int flow;
	int pv;
	//���캯��
	sightTree(int id) :sightID(id), lchild(NULL), rchild(NULL), chain(NULL), flow(0), pv(0) {}

	//����
	void insertnode(int newid,sightTree *root);
	int deletenode(int newid,sightTree *root);
	sightTree* search(int newid, sightTree *&root);

	//����
	void inorder(sightTree *tree);
	void preorder(sightTree *tree);

};

//��������������
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



//��������������
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

//������������ɾ��
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





//�������
void sightTree::inorder(sightTree *tree)
{
	if (tree != NULL) {
		inorder(tree->lchild);
		cout << tree->sightID << endl;
		inorder(tree->rchild);
	}
}

//ǰ�����
void sightTree::preorder(sightTree *tree)
{
	if (tree != NULL) {
		cout << tree->sightID << endl;
		inorder(tree->lchild);
		inorder(tree->rchild);
	}
}

