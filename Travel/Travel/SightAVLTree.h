#pragma once
#include<iomanip>
#include<iostream>
#include<string>
#include"Guestchain.h"

using namespace std;

class sightAVLTreeNode {
public:
	int sightID;
	int height;
	string sightName;
	sightAVLTreeNode *lchild;
	sightAVLTreeNode *rchild;
	guestchain *chain;//������ָ��
	int flow;
	int pv;

	//���캯��
	sightAVLTreeNode(int newid, string newname, sightAVLTreeNode *l, sightAVLTreeNode *r) :sightID(newid), sightName(newname), chain(NULL), lchild(l), rchild(r), flow(0), pv(0) {}
};

//����Ķ���������
class sightAVLTree {
public:
	sightAVLTree() :TreeRoot(NULL) {}
	~sightAVLTree() { destory(TreeRoot); }
	//��ȡ���߶�
	int height();
	int max(int a, int b);

	//������
	void preOrder();
	void preOrderPV();
	void preOrderAll();

	void inOrder();

	void postOrder();

	//����
	sightAVLTreeNode* search(int newid);	//�ݹ�
	int minimun();
	int maximun();

	//����
	void insert(int newid, string newname);
	//ɾ��
	void remove(int newid);

	void destory();
	void print();

private:
	int height(sightAVLTreeNode* tree);

	//����
	void preOrder(sightAVLTreeNode *tree);
	void preOrderPV(sightAVLTreeNode *tree);
	void preOrderAll(sightAVLTreeNode *tree);

	void inOrder(sightAVLTreeNode *tree);

	void postOrder(sightAVLTreeNode *tree);

	//����
	sightAVLTreeNode* search(int newid, sightAVLTreeNode *x);
	sightAVLTreeNode* minimun(sightAVLTreeNode* tree);
	sightAVLTreeNode* maximun(sightAVLTreeNode* tree);

	//��ת
	sightAVLTreeNode* LLRotate(sightAVLTreeNode* k2);
	sightAVLTreeNode* RRRotate(sightAVLTreeNode* k1);
	sightAVLTreeNode* LRRotate(sightAVLTreeNode* k3);
	sightAVLTreeNode* RLRotate(sightAVLTreeNode* k1);

	//����
	sightAVLTreeNode* insert(sightAVLTreeNode* &tree, int newid, string newname);

	//ɾ��
	sightAVLTreeNode* remove(sightAVLTreeNode* &tree, sightAVLTreeNode* z);

	sightAVLTreeNode *TreeRoot;

	void destory(sightAVLTreeNode* &tree);
};

int sightAVLTree::height(sightAVLTreeNode* tree)
{
	if (tree != NULL) {
		return tree->height;
	}
	return 0;
}

int sightAVLTree::height() {
	return height(TreeRoot);
}

int sightAVLTree::max(int a, int b) {
	return a > b ? a : b;
}

//ǰ�����
void sightAVLTree::preOrder(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		cout << tree->sightID << " ";
		preOrder(tree->lchild);
		preOrder(tree->rchild);
	}
}

void sightAVLTree::preOrderPV(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		cout << tree->sightID << " ���ƣ�"<<tree->sightName<<" ԤԼ����Ϊ��" << tree->pv << endl;
		preOrderPV(tree->lchild);
		preOrderPV(tree->rchild);
	}
}

void sightAVLTree::preOrderAll(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		cout << tree->sightID << " ���ƣ�" << tree->sightName << " ԤԼ����Ϊ��" << tree->pv << endl;
		tree->chain->printall();
		preOrderAll(tree->lchild);
		preOrderAll(tree->rchild);
	}
}



void sightAVLTree::preOrder() {
	preOrder(TreeRoot);
}

void sightAVLTree::preOrderPV() {
	preOrderPV(TreeRoot);
}

void sightAVLTree::preOrderAll() {
	preOrderAll(TreeRoot);
}

//�������
void sightAVLTree::inOrder(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		inOrder(tree->lchild);
		cout << tree->sightID << " ";
		inOrder(tree->rchild);
	}
}

void sightAVLTree::inOrder() {
	inOrder(TreeRoot);
}
//�������
void sightAVLTree::postOrder(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		postOrder(tree->lchild);
		postOrder(tree->rchild);
		cout << tree->sightID << " ";
	}
}

void sightAVLTree::postOrder() {
	postOrder(TreeRoot);
}

//���Ҿ���
sightAVLTreeNode * sightAVLTree::search(int newid, sightAVLTreeNode * x)
{
	if (x == NULL || x->sightID == newid)
		return x;
	if (newid < x->sightID)
		return search(newid, x->lchild);
	else
		return search(newid, x->rchild);
}

sightAVLTreeNode * sightAVLTree::search(int newid)
{
	return search(newid, TreeRoot);
}

sightAVLTreeNode * sightAVLTree::minimun(sightAVLTreeNode * tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->lchild != NULL)
	{
		tree = tree->lchild;
	}
	return tree;
}

int sightAVLTree::minimun()
{
	sightAVLTreeNode *p = minimun(TreeRoot);
	if (p != NULL)
		return p->sightID;

	return (int)NULL;
}


sightAVLTreeNode * sightAVLTree::maximun(sightAVLTreeNode * tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->rchild != NULL)
	{
		tree = tree->rchild;
	}
	return tree;
}

int sightAVLTree::maximun() {
	sightAVLTreeNode* p = maximun(TreeRoot);
	if (p != NULL)
		return p->sightID;

	return (int)NULL;
}

//LL��ת
sightAVLTreeNode* sightAVLTree::LLRotate(sightAVLTreeNode* k2) {
	sightAVLTreeNode* k1;
	k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;

	k2->height = max(height(k2->lchild), height(k2->rchild)) + 1;
	k1->height = max(height(k1->lchild), k2->height) + 1;

	return k1;
}
//RR��ת
sightAVLTreeNode* sightAVLTree::RRRotate(sightAVLTreeNode* k1) {
	sightAVLTreeNode* k2;

	k2 = k1->rchild;
	k1->rchild = k2->lchild;
	k2->lchild = k1;

	k1->height = max(height(k1->lchild), height(k1->rchild)) + 1;
	k2->height = max(height(k2->rchild), k1->height) + 1;

	return k2;
}
//LR��ת
sightAVLTreeNode* sightAVLTree::LRRotate(sightAVLTreeNode* k3) {
	k3->lchild = RRRotate(k3->lchild);

	return LLRotate(k3);
}
//RL��ת
sightAVLTreeNode* sightAVLTree::RLRotate(sightAVLTreeNode* k1) {
	k1->rchild = LLRotate(k1->rchild);

	return RRRotate(k1);
}


//����ڵ�
sightAVLTreeNode* sightAVLTree::insert(sightAVLTreeNode* &tree, int newid, string newname)
{
	if (tree == NULL)
	{
		// �½��ڵ�
		tree = new sightAVLTreeNode(newid, newname, NULL, NULL);
		if (tree == NULL)
		{
			cout << "ERROR: create avltree node failed!" << endl;
			return NULL;
		}
	}
	else if (newid < tree->sightID) // Ӧ�ý�key���뵽"tree��������"�����
	{
		tree->lchild = insert(tree->lchild, newid, newname);
		// ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->lchild) - height(tree->rchild) == 2)
		{
			if (newid < tree->lchild->sightID)
				tree = LLRotate(tree);
			else
				tree = LRRotate(tree);
		}
	}
	else if (newid > tree->sightID) // Ӧ�ý�key���뵽"tree��������"�����
	{
		tree->rchild = insert(tree->rchild, newid, newname);
		// ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->rchild) - height(tree->lchild) == 2)
		{
			if (newid > tree->rchild->sightID)
				tree = RRRotate(tree);
			else
				tree = RLRotate(tree);
		}
	}
	else //key == tree->key)
	{
		cout << "���ʧ�ܣ������������ͬ�Ľڵ㣡" << endl;
	}

	tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;

	return tree;
}

void sightAVLTree::insert(int newid, string itsname)
{
	insert(TreeRoot, newid, itsname);
}

//ɾ���ڵ�
sightAVLTreeNode* sightAVLTree::remove(sightAVLTreeNode* &tree, sightAVLTreeNode* z)
{
	// ��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL��
	if (tree == NULL || z == NULL)
		return NULL;

	if (z->sightID < tree->sightID)        // ��ɾ���Ľڵ���"tree��������"��
	{
		tree->lchild = remove(tree->lchild, z);
		// ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->rchild) - height(tree->lchild) == 2)
		{
			sightAVLTreeNode *r = tree->rchild;
			if (height(r->lchild) > height(r->rchild))
				tree = RLRotate(tree);
			else
				tree = RRRotate(tree);
		}
	}
	else if (z->sightID > tree->sightID)// ��ɾ���Ľڵ���"tree��������"��
	{
		tree->rchild = remove(tree->rchild, z);
		// ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
		if (height(tree->lchild) - height(tree->rchild) == 2)
		{
			sightAVLTreeNode *l = tree->lchild;
			if (height(l->rchild) > height(l->lchild))
				tree = LRRotate(tree);
			else
				tree = LLRotate(tree);
		}
	}
	else    // tree�Ƕ�ӦҪɾ���Ľڵ㡣
	{
		// tree�����Һ��Ӷ��ǿ�
		if ((tree->lchild != NULL) && (tree->rchild != NULL))
		{
			if (height(tree->lchild) > height(tree->rchild))
			{
				// ���tree�����������������ߣ�
				// ��(01)�ҳ�tree���������е����ڵ�
				//   (02)�������ڵ��ֵ��ֵ��tree��
				//   (03)ɾ�������ڵ㡣
				// ����������"tree�������������ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
				sightAVLTreeNode* max = maximun(tree->lchild);
				tree->sightID = max->sightID;
				tree->lchild = remove(tree->lchild, max);
			}
			else
			{
				// ���tree��������������������(��������ȣ�������������������1)
				// ��(01)�ҳ�tree���������е���С�ڵ�
				//   (02)������С�ڵ��ֵ��ֵ��tree��
				//   (03)ɾ������С�ڵ㡣
				// ����������"tree������������С�ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
				sightAVLTreeNode* min = minimun(tree->rchild);
				tree->sightID = min->sightID;
				tree->rchild = remove(tree->rchild, min);
			}
		}
		else
		{
			sightAVLTreeNode* tmp = tree;
			tree = (tree->lchild != NULL) ? tree->lchild : tree->rchild;
			delete tmp;
		}
	}

	return tree;
}

void sightAVLTree::remove(int newid)
{
	sightAVLTreeNode* z;

	if ((z = search(newid, TreeRoot)) != NULL)
		TreeRoot = remove(TreeRoot, z);
}

void sightAVLTree::destory(sightAVLTreeNode* &tree)
{
	if (tree == NULL)
		return;
	if (tree->lchild != NULL)
		destory(tree->lchild);
	if (tree->rchild != NULL)
		destory(tree->rchild);

	delete tree;
}

void sightAVLTree::destory() {
	destory(TreeRoot);
}