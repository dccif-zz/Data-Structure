#pragma once
#include"Guestchain.h"
#include<string>

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
	sightAVLTreeNode(int newid, string newname, sightAVLTreeNode *l, sightAVLTreeNode *r) :sightID(newid), sightName(newname), lchild(l), rchild(r) {}
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
	void inOrder();
	void postOrder();

	//����
	sightAVLTreeNode* search(int newid);	//�ݹ�

	//����
	void insert(int newid, string newname);
	//ɾ��
	void remove(int newid);

	void destory();
	void print();

private:
	int TreeHeight(sightAVLTreeNode* tree);

	//����
	void preOrder(sightAVLTreeNode *tree);
	void inOrder(sightAVLTreeNode *tree);
	void postOrder(sightAVLTreeNode *tree);

	//����
	sightAVLTreeNode* search(int newid, sightAVLTreeNode *x);

	//��ת
	sightAVLTreeNode* LLRotate(sightAVLTreeNode* k2);
	sightAVLTreeNode* RRRotate(sightAVLTreeNode* k1);
	sightAVLTreeNode* LRRotate(sightAVLTreeNode* k3);
	sightAVLTreeNode* RLRotate(sightAVLTreeNode* k1);

	//����
	sightAVLTreeNode* insert(sightAVLTreeNode* &tree, int newid);

	//ɾ��
	sightAVLTreeNode* remove(sightAVLTreeNode* &tree, sightAVLTreeNode* z);

	sightAVLTreeNode *TreeRoot;

	void destory(sightAVLTreeNode* &tree);
};

int sightAVLTree::TreeHeight(sightAVLTreeNode* tree)
{
	if (tree != NULL) {
		return tree->height;
	}
	return 0;
}

int sightAVLTree::height() {
	return TreeHeight(TreeRoot);
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

void sightAVLTree::preOrder() {
	preOrder(TreeRoot);
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


