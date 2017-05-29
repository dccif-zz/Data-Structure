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
void Build(LinkList L)//����һ����ͷ���ĵ�����
{
	int n;
	LinkList p, q;
	p = L;
	printf("������n��n������Ԫ��:\n");
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
void Print(LinkList L)//���㵥����ĳ��ȣ�Ȼ�����������
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
	printf("\n����Ϊ%d:\n", num);
}
void Tips()
{
	printf("�����ּ�ѡ����Ӧ����\n");
	printf("<1> ����������䳤��:\n");
	printf("<2> ɾ��ֵΪx�Ľ��:\n");
	printf("<3> ������Ԫ������:\n");
	printf("<4> ɾ����������ֵ��ͬ�Ķ���Ԫ��:\n");
	printf("<5> ����Ԫ��:\n");
	printf("<0> �˳�:\n");
}

void Delete(LinkList L, int x)//ɾ��ֵΪx�Ľ��
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
		printf("ɾ���ɹ�!!\n\n");
	}
	else
		printf("������û��%d\n\n", x);
}
void NiZhi(LinkList L)//�ѵ���������Ԫ������,������ͷ�巨��������!
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
	printf("���óɹ�!!!\n\n");
}

void Delete2(LinkList L)//ɾ����������ֵ��ͬ�Ķ���Ԫ�أ�ʹ�ò���������Ա�������Ԫ�ص�ֵ������ͬ����
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
	printf("ɾ���ɹ�!!!!\n");
}

void Insert(LinkList L, LinkList p)//�������������ֵΪX�Ľ�㣬ʹ��Ȼ����
{
	LinkList s;
	s = L;
	while (s->next && s->next->data < p->data)
		s = s->next;
	p->next = s->next;
	s->next = p;
}
status Sort(LinkList L)//����������
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
			printf("������Ҫ���ҵ�ɾ��X:\n");
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
			printf("������Ҫ�����Ԫ��X:\n");
			scanf("%d", &x);
			p = (LinkList)malloc(sizeof(LNode));
			p->data = x;
			Insert(L, p);
			printf("����ɹ�!!!\n\n");
			break;
		}
		Tips();
		scanf("%d", &op);
	}
	return 0;
}