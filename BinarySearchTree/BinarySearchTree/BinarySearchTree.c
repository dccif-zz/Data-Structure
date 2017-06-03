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

bitree ins(bitree t, bitree f, int x)//�����������в���x
{
	bitree s;
	s = (bitree)malloc(sizeof(binode));
	s->data = x; s->lchild = s->rchild = NULL;
	if (t == NULL) t = s;
	else if (s->data<f->data) f->lchild = s;
	else f->rchild = s;
	return t;
}
bitree del(bitree t, bitree p, bitree f) //ɾ��������������pָ�Ľ��
{
	bitree q, child;   //tΪ��ָ�롢pָ��ɾ��㡢f��p��ǰ��ָ��
	if (p->lchild&&p->rchild) {//��ɾ�������������
		q = f = p; p = p->rchild;
		while (p->lchild != NULL) {//��p��������
			f = p; p = p->lchild;
		}
		q->data = p->data;//
	}//pת��Ϊֻ��һ��������
	if (p->lchild) child = p->lchild;  //��ɾ�����������
	else child = p->rchild; //��ɾ�����������
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
	printf("\n����xֵ��");
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
		if (p == NULL) { root = ins(root, f, x); printf("�������"); }
		else { root = del(root, p, f); printf("ɾ�����"); }
		printf("\n��������x,ֱ������0Ϊֹ");
		scanf("%d", &x);
	}
	printf("\n������������ǰ��Ϊ;");
	preorder(root);
	printf("\n");
}
