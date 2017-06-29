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
	void insertnode(int newid);
	void deletenode(int newid);

	//����
	void inorder(sightTree *tree);
	void preorder(sightTree *tree);
};

//��������������
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

