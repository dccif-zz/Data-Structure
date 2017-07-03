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
	guestchain *chain;//单链表指针
	int flow;
	int pv;

	//构造函数
	sightAVLTreeNode(int newid, string newname, sightAVLTreeNode *l, sightAVLTreeNode *r) :sightID(newid), sightName(newname), lchild(l), rchild(r) {}
};

//景点的二叉排序树
class sightAVLTree {
public:
	sightAVLTree() :TreeRoot(NULL) {}
	~sightAVLTree() { destory(TreeRoot); }
	//获取树高度
	int height();
	int max(int a, int b);

	//遍历树
	void preOrder();
	void inOrder();
	void postOrder();

	//查找
	sightAVLTreeNode* search(int newid);	//递归

	//插入
	void insert(int newid, string newname);
	//删除
	void remove(int newid);

	void destory();
	void print();

private:
	int TreeHeight(sightAVLTreeNode* tree);

	//遍历
	void preOrder(sightAVLTreeNode *tree);
	void inOrder(sightAVLTreeNode *tree);
	void postOrder(sightAVLTreeNode *tree);

	//查找
	sightAVLTreeNode* search(int newid, sightAVLTreeNode *x);

	//旋转
	sightAVLTreeNode* LLRotate(sightAVLTreeNode* k2);
	sightAVLTreeNode* RRRotate(sightAVLTreeNode* k1);
	sightAVLTreeNode* LRRotate(sightAVLTreeNode* k3);
	sightAVLTreeNode* RLRotate(sightAVLTreeNode* k1);

	//插入
	sightAVLTreeNode* insert(sightAVLTreeNode* &tree, int newid);

	//删除
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

//前序遍历
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
//中序遍历
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
//后序遍历
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


