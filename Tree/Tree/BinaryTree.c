#include<stdio.h>
#define TElemType int


//�������ṹ
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


//���õݹ鹹�������
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
			printf("����%d�����ӽڵ㣺", val);
			createBTree(&((*root)->lchild));
			printf("����%d�����ӽڵ㣺", val);
			createBTree(&((*root)->rchild));
		}
	}

	return 1;
}


//�������
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

//�������
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

//�������
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

//��ȼ���
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

//������
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

//����
int main() {
	BiTNode *myTree;
	int deep, count = 0;
	printf("�������һ�����ֵ��-1��ʾû�У�\n");
	createBTree(&myTree);

	printf("���������");
	PreOrderBiTree(myTree);
	printf("\n");

	printf("���������");
	MiddleOrderBiTree(myTree);
	printf("\n");

	printf("���������");
	PostOrderBiTree(myTree);
	printf("\n");

	deep = TreeDeep(myTree);
	printf("�������Ϊ��%d\n", deep);

	count = NodeCount(myTree);
	printf("��������%d\n", count);

	system("pause");
	return 0;
}