#include<stdio.h>
#define TElemType int


//二叉树结构
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


//利用递归构造二叉树
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


//先序遍历
void PreOrderBiTree(BiTNode *T) {
	if (T == NULL) {
		return;
	}
	else
	{
		printf("%d", T->data);
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}

//中序遍历
void MiddleOrderBiTree(BiTNode *T) {
	if (T == NULL) {
		return;
	}
	else
	{
		MiddleOrderBiTree(T->lchild);
		printf("%d", T->data);
		MiddleOrderBiTree(T->rchild);
	}
}

//后序遍历
void PostOrderBiTree(BiTNode *T) {
	if (T == NULL) {
		return;
	}
	else
	{
		PostOrderBiTree(T->lchild);
		PostOrderBiTree(T->rchild);
		printf("%d", T->data);
	}
}

//深度计算
int TreeDeep(BiTNode *T) {
	int deep = 0;
	if (T != NULL) {
		int leftdeep = TreeDeep(T->lchild);
		int rightdeep = TreeDeep(T->rchild);
		if (leftdeep >= rightdeep) {
			deep = leftdeep + 1;
		}
		else
		{
			deep = rightdeep + 1;
		}
	}
	return deep;
}

//结点计数
int NodeCount(BiTNode *T) {
	static int count = 0;
	if (T != NULL) {
		return 0;
	}
	else {
		count =1+ NodeCount(T->lchild) + NodeCount(T->rchild);
	}
	return count;
}

//测试
int main() {
	BiTNode *myTree;
	int deep, count = 0;
	printf("请输入第一个结点值，-1表示没有：\n");
	createBTree(&myTree);

	printf("先序遍历：");
	PreOrderBiTree(myTree);
	printf("\n");

	printf("中序遍历：");
	MiddleOrderBiTree(myTree);
	printf("\n");

	printf("后序遍历：");
	PostOrderBiTree(myTree);
	printf("\n");

	deep = TreeDeep(myTree);
	printf("树的深度为：%d\n", deep);

	count = NodeCount(myTree);
	printf("结点个数：%d\n", count);

	system("pause");
	return 0;
}