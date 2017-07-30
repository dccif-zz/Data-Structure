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
	guestchain *chain;//单链表指针
	int flow;
	int pv;

	//构造函数
	sightAVLTreeNode(int newid, string newname, sightAVLTreeNode *l, sightAVLTreeNode *r) :sightID(newid), sightName(newname), chain(NULL), lchild(l), rchild(r), flow(0), pv(0) {}
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
	void preOrderPV();
	void preOrderAll();

	void inOrder();
	void inOrderPV();
	void inOrderAll();

	void postOrder();
	void postOrderPV();
	void postOrderAll();

	//查找
	sightAVLTreeNode* search(int newid);	//递归
	int minimun();
	int maximun();

	//插入
	void insert(int newid, string newname);
	//删除
	void remove(int newid);

	void destory();

private:
	int height(sightAVLTreeNode* tree);

	//遍历
	void preOrder(sightAVLTreeNode *tree);
	void preOrderPV(sightAVLTreeNode *tree);
	void preOrderAll(sightAVLTreeNode *tree);

	void inOrder(sightAVLTreeNode *tree);
	void inOrderPV(sightAVLTreeNode *tree);
	void inOrderAll(sightAVLTreeNode *tree);

	void postOrder(sightAVLTreeNode *tree);
	void postOrderPV(sightAVLTreeNode *tree);
	void postOrderAll(sightAVLTreeNode *tree);

	//查找
	sightAVLTreeNode* search(int newid, sightAVLTreeNode *x);
	sightAVLTreeNode* minimun(sightAVLTreeNode* tree);
	sightAVLTreeNode* maximun(sightAVLTreeNode* tree);

	//旋转
	sightAVLTreeNode* LLRotate(sightAVLTreeNode* k2);
	sightAVLTreeNode* RRRotate(sightAVLTreeNode* k1);
	sightAVLTreeNode* LRRotate(sightAVLTreeNode* k3);
	sightAVLTreeNode* RLRotate(sightAVLTreeNode* k1);

	//插入
	sightAVLTreeNode* insert(sightAVLTreeNode* &tree, int newid, string newname);

	//删除
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

//前序遍历
void sightAVLTree::preOrder(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		cout << tree->sightID << " ";
		preOrder(tree->lchild);
		preOrder(tree->rchild);
	}
}

void sightAVLTree::preOrderPV(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		cout << tree->sightID << " 名称：" << tree->sightName << " 预约人数为：" << tree->pv << endl;
		preOrderPV(tree->lchild);
		preOrderPV(tree->rchild);
	}
}

void sightAVLTree::preOrderAll(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		cout << tree->sightID << " 名称：" << tree->sightName << " 预约人数为：" << tree->pv << endl;
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

//中序遍历
void sightAVLTree::inOrder(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		inOrder(tree->lchild);
		cout << tree->sightID << " ";
		inOrder(tree->rchild);
	}
}

void sightAVLTree::inOrderPV(sightAVLTreeNode * tree)
{
	if (tree != NULL) {
		inOrderPV(tree->lchild);
		cout << tree->sightID << " 名称：" << tree->sightName << " 预约人数为：" << tree->pv << endl;
		inOrderPV(tree->rchild);
	}
}

void sightAVLTree::inOrderAll(sightAVLTreeNode * tree)
{
	if (tree != NULL) {
		inOrderAll(tree->lchild);
		cout << tree->sightID << " 名称：" << tree->sightName << " 预约人数为：" << tree->pv << endl;
		tree->chain->printall();
		inOrderAll(tree->rchild);
	}
}

void sightAVLTree::inOrder() {
	inOrder(TreeRoot);
}
void sightAVLTree::inOrderPV()
{
	inOrderPV(TreeRoot);
}
void sightAVLTree::inOrderAll()
{
	inOrderAll(TreeRoot);
}
//后序遍历
void sightAVLTree::postOrder(sightAVLTreeNode* tree) {
	if (tree != NULL) {
		postOrder(tree->lchild);
		postOrder(tree->rchild);
		cout << tree->sightID << " ";
	}
}

void sightAVLTree::postOrderPV(sightAVLTreeNode * tree)
{
	postOrderPV(tree->lchild);
	postOrderPV(tree->rchild);
	cout << tree->sightID << " 名称：" << tree->sightName << " 预约人数为：" << tree->pv << endl;
}

void sightAVLTree::postOrderAll(sightAVLTreeNode * tree)
{
	postOrderAll(tree->lchild);
	postOrderAll(tree->rchild);
	cout << tree->sightID << " 名称：" << tree->sightName << " 预约人数为：" << tree->pv << endl;
	tree->chain->printall();
}

void sightAVLTree::postOrder() {
	postOrder(TreeRoot);
}

inline void sightAVLTree::postOrderPV()
{
	postOrderPV(TreeRoot);
}

void sightAVLTree::postOrderAll()
{
	postOrderAll(TreeRoot);
}

//查找景点
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

//LL旋转
sightAVLTreeNode* sightAVLTree::LLRotate(sightAVLTreeNode* k2) {
	sightAVLTreeNode* k1;
	k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;

	k2->height = max(height(k2->lchild), height(k2->rchild)) + 1;
	k1->height = max(height(k1->lchild), k2->height) + 1;

	return k1;
}
//RR旋转
sightAVLTreeNode* sightAVLTree::RRRotate(sightAVLTreeNode* k1) {
	sightAVLTreeNode* k2;

	k2 = k1->rchild;
	k1->rchild = k2->lchild;
	k2->lchild = k1;

	k1->height = max(height(k1->lchild), height(k1->rchild)) + 1;
	k2->height = max(height(k2->rchild), k1->height) + 1;

	return k2;
}
//LR旋转
sightAVLTreeNode* sightAVLTree::LRRotate(sightAVLTreeNode* k3) {
	k3->lchild = RRRotate(k3->lchild);

	return LLRotate(k3);
}
//RL旋转
sightAVLTreeNode* sightAVLTree::RLRotate(sightAVLTreeNode* k1) {
	k1->rchild = LLRotate(k1->rchild);

	return RRRotate(k1);
}


//插入节点
sightAVLTreeNode* sightAVLTree::insert(sightAVLTreeNode* &tree, int newid, string newname)
{
	if (tree == NULL)
	{
		// 新建节点
		tree = new sightAVLTreeNode(newid, newname, NULL, NULL);
		if (tree == NULL)
		{
			cout << "ERROR: create avltree node failed!" << endl;
			return NULL;
		}
	}
	else if (newid < tree->sightID) // 应该将key插入到"tree的左子树"的情况
	{
		tree->lchild = insert(tree->lchild, newid, newname);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->lchild) - height(tree->rchild) == 2)
		{
			if (newid < tree->lchild->sightID)
				tree = LLRotate(tree);
			else
				tree = LRRotate(tree);
		}
	}
	else if (newid > tree->sightID) // 应该将key插入到"tree的右子树"的情况
	{
		tree->rchild = insert(tree->rchild, newid, newname);
		// 插入节点后，若AVL树失去平衡，则进行相应的调节。
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
		cout << "添加失败：不允许添加相同的节点！" << endl;
	}

	tree->height = max(height(tree->lchild), height(tree->rchild)) + 1;

	return tree;
}

void sightAVLTree::insert(int newid, string itsname)
{
	insert(TreeRoot, newid, itsname);
}

//删除节点
sightAVLTreeNode* sightAVLTree::remove(sightAVLTreeNode* &tree, sightAVLTreeNode* z)
{
	// 根为空 或者 没有要删除的节点，直接返回NULL。
	if (tree == NULL || z == NULL)
		return NULL;

	if (z->sightID < tree->sightID)        // 待删除的节点在"tree的左子树"中
	{
		tree->lchild = remove(tree->lchild, z);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->rchild) - height(tree->lchild) == 2)
		{
			sightAVLTreeNode *r = tree->rchild;
			if (height(r->lchild) > height(r->rchild))
				tree = RLRotate(tree);
			else
				tree = RRRotate(tree);
		}
	}
	else if (z->sightID > tree->sightID)// 待删除的节点在"tree的右子树"中
	{
		tree->rchild = remove(tree->rchild, z);
		// 删除节点后，若AVL树失去平衡，则进行相应的调节。
		if (height(tree->lchild) - height(tree->rchild) == 2)
		{
			sightAVLTreeNode *l = tree->lchild;
			if (height(l->rchild) > height(l->lchild))
				tree = LRRotate(tree);
			else
				tree = LLRotate(tree);
		}
	}
	else    // tree是对应要删除的节点。
	{
		// tree的左右孩子都非空
		if ((tree->lchild != NULL) && (tree->rchild != NULL))
		{
			if (height(tree->lchild) > height(tree->rchild))
			{
				// 如果tree的左子树比右子树高；
				// 则(01)找出tree的左子树中的最大节点
				//   (02)将该最大节点的值赋值给tree。
				//   (03)删除该最大节点。
				// 这类似于用"tree的左子树中最大节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
				sightAVLTreeNode* max = maximun(tree->lchild);
				tree->sightID = max->sightID;
				tree->sightName = max->sightName;
				tree->lchild = remove(tree->lchild, max);
			}
			else
			{
				// 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
				// 则(01)找出tree的右子树中的最小节点
				//   (02)将该最小节点的值赋值给tree。
				//   (03)删除该最小节点。
				// 这类似于用"tree的右子树中最小节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
				sightAVLTreeNode* min = minimun(tree->rchild);
				tree->sightID = min->sightID;
				tree->sightName = min->sightName;
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