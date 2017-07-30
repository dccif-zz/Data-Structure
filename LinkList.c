#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK    1
typedef int status;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
} LNode, *LinkList;
void Build(LinkList L)//建立一个带头结点的单链表
{
	int n;
	LinkList p, q;
	p = L;
	printf("请输入n和n个数据元素:\n");
	scanf("%d", &n);
	while (n--)
	{
		q = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &q->data);
		q->next = NULL;
		p->next = q;
		p = q;
	}
}
void Print(LinkList L)//计算单链表的长度，然后输出单链表
{
	int num = 0;
	LinkList p;
	p = L->next;
	while (p)
	{
		num++;
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n长度为%d:\n", num);
}
void Tips()
{
	printf("按数字键选择相应操作\n");
	printf("<1> 输出单链表及其长度:\n");
	printf("<2> 删除值为x的结点:\n");
	printf("<3> 将表中元素逆置:\n");
	printf("<4> 删除表中所有值相同的多余元素:\n");
	printf("<5> 插入元素:\n");
	printf("<0> 退出:\n");
}

void Delete(LinkList L, int x)//删除值为x的结点
{
	LinkList p, q;
	p = L;
	while (p->next && p->next->data != x)
		p = p->next;
	if (p->next)
	{
		q = p->next;
		p->next = q->next;
		free(q);
		printf("删除成功!!\n\n");
	}
	else
		printf("链表中没有%d\n\n", x);
}
void NiZhi(LinkList L)//把单向链表中元素逆置,类似于头插法建立链表!
{
	LinkList p, s;
	p = s = L->next;
	L->next = NULL;
	while (p)
	{
		s = s->next;
		p->next = L->next;
		L->next = p;
		p = s;
	}
	printf("逆置成功!!!\n\n");
}

void Delete2(LinkList L)//删除表中所有值相同的多余元素（使得操作后的线性表中所有元素的值均不相同），
{
	LinkList p, q, s;
	p = L;
	q = L->next;
	while (q->next)
	{
		if (q->data == q->next->data)
		{
			p->next = q->next;
			s = q;
			q = q->next;
			free(s);
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	printf("删除成功!!!!\n");
}

void Insert(LinkList L, LinkList p)//在升序链表插入值为X的结点，使仍然有序
{
	LinkList s;
	s = L;
	while (s->next && s->next->data < p->data)
		s = s->next;
	p->next = s->next;
	s->next = p;
}
status Sort(LinkList L)//按升序排列
{
	LinkList s, r;
	s = L->next;
	L->next = NULL;
	while (s)
	{
		r = s;
		s = s->next;
		r->next = NULL;
		Insert(L, r);
	}
	return OK;
}
int main()
{
	int op, x, flag;
	LinkList L, p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = -1;
	Build(L);
	Tips();
	scanf("%d", &op);
	while (op)
	{
		switch (op)
		{
		case 1:
			Print(L);
			break;
		case 2:
			printf("请输入要查找的删除X:\n");
			scanf("%d", &x);
			Delete(L, x);
			break;
		case 3:
			NiZhi(L);
			break;
		case 4:
			Delete2(L);
			break;
		case 5:
			printf("请输入要插入的元素X:\n");
			scanf("%d", &x);
			p = (LinkList)malloc(sizeof(LNode));
			p->data = x;
			Insert(L, p);
			printf("插入成功!!!\n\n");
			break;
		}
		Tips();
		scanf("%d", &op);
	}
	return 0;
}