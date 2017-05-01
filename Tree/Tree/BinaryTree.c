#include<stdio.h>
#define TElemType int

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

int createBTree(BiTree *root) {
	TElemType val;
	scanf_s("%d", &val);
	if (val == -1){
		*root = NULL;
		return 0;
	}
	else {
		*root = (BiTree)malloc(sizeof(BiTNode));
		if (root == NULL) {
			printf("failed\n");
			return 0;
		}
		else
		{
			(*root)->data = val;
			printf("输入%d的左子节点：", val);
			createBTree(&((*root)->lchild));
			printf("输入%d的右子节点：", val);
			createBTree(&((*root)->rchild));
		}
	}

	return 1;
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
	BiTNode *myTree;
	//BiTree myNode;
	createBTree(&myTree);
}