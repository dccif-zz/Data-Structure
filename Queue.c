#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


#ifdef __cplusplus
extern "C" {
#endif
#define QElement int
#define Status int

typedef struct QNode {
	QElement data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(3);
	Q->front->next = NULL;
	return 0;
}

Status DestoryQueue(LinkQueue *Q) {
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return 0;
}

Status EnQueue(LinkQueue *Q, QElement e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(3);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return 0;
}

Status DeQueue(LinkQueue *Q, QElement e) {
	QueuePtr p;
	if (Q->front == Q->rear) return 3;
	p = Q->front->next;
	e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return 0;

}

int main() {
	LinkQueue Q;
	InitQueue(&Q);
	system("pause");
}
