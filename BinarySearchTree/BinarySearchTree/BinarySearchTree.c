#include<stdio.h>
#include<malloc.h>

#define M 100

typedef struct binode {
	int data;
	struct binode *lchild, *rchild;
}binode,*bitree;

void preorder(bitree t) {
	int top = 0;
	bitree p, s[M];
	p = t;
	do {
		while (p != NULL) {
			printf("%d\t", p->data);
			if (p->rchild != NULL)
				s[top++] = p->rchild;
			p = p->lchild;
		}
		if (top > -0)
		{
			p = s[--top];
		}
	} while (top >= 0);

}

bitree ins(bitree t, bitree f, int x)//二叉排序树中插入x
{
	bitree s;
	s = (bitree)malloc(sizeof(binode));
	s->data = x; s->lchild = s->rchild = NULL;
	if (t == NULL) t = s;
	else if (s->data<f->data) f->lchild = s;
	else f->rchild = s;
	return t;
}
bitree del(bitree t, bitree p, bitree f) //删除二叉排序树中p指的结点
{
	bitree q, child;   //t为根指针、p指被删结点、f是p的前驱指针
	if (p->lchild&&p->rchild) {//被删结点有左、右子树
		q = f = p; p = p->rchild;
		while (p->lchild != NULL) {//找p的中序后继
			f = p; p = p->lchild;
		}
		q->data = p->data;//
	}//p转化为只有一个子树了
	if (p->lchild) child = p->lchild;  //被删结点有左子树
	else child = p->rchild; //被删结点有右子树
		if (f == NULL)t = child;
		else if (p == f->lchild)f->lchild = child;
		else f->rchild = child;
		free(p);
		return t;
}
void main()
{
	bitree root = NULL, p, f;
	int x;
	printf("\n输入x值：");
	scanf("%d", &x);
	while (x != 0)
	{
		p = root; f = NULL;
		while (p &&p->data != x)
		{
			f = p;
			if (x<p->data) p = p->lchild;
			else p = p->rchild;
		}
		if (p == NULL) { root = ins(root, f, x); printf("插入完成"); }
		else { root = del(root, p, f); printf("删除完成"); }
		printf("\n继续输入x,直到输入0为止");
		scanf("%d", &x);
	}
	printf("\n二叉排序树的前序为;");
	preorder(root);
	printf("\n");
}
