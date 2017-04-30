#include<stdio.h>
#define TElemType int

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void createBTree(BiTree *root) {
	TElemType val;
	val = getchar();
	if (val == '#')
		*root = NULL;
	else {
		*root = (BiTree)malloc(sizeof(BiTNode));
		(*root)->data = val;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		createBTree(&(*root)->lchild);
		createBTree(&(*root)->rchild);
	}
}





void insertLeftTree(BiTree root, int val) {
	BiTree p, newNode;
	if (root == NULL)
		return;
	p = root->lchild;
	newNode = (BiTree)malloc(sizeof(BiTNode));
	newNode->data = val;
	newNode->rchild = NULL;
	newNode->lchild = p;
	root->lchild = newNode;
}

void insertRightTree(BiTree root, int val) {
	BiTree p, newNode;
	if (root == NULL)
		return;
	p = root->rchild;
	newNode = (BiTree)malloc(sizeof(BiTNode));
	newNode->data = val;
	newNode->lchild = NULL;
	newNode->rchild = p;
	root->rchild = newNode;
}


int main() {
	BiTNode *myNode;
	//BiTree myNode;
	createBTree(myNode);
	insertLeftTree(myNode, 5);
}