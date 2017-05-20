#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10

typedef enum { FALSE,TRUE } Boolean;

typedef struct node {
	int adjvex;
	struct node *next;
}EdgeNode;

typedef struct vnode {
	char vextex;
	EdgeNode *firstedge;
}VertexNode;

typedef struct {
	VertexNode adjlist[MAX];
	int n, e;
}ALGraph;


typedef struct {
	char vexs[MAX];
	int edges[MAX][MAX];
	int n, e;
}MyGraph;   //Matrix

Boolean visited[MAX];

//Create ALGraph
void CreateALGraph(ALGraph *G) {
	EdgeNode *s;
	int i, j, k;
	printf("输入图的顶点数n，边数e：");
	scanf("%d,%d", &(G->n), &(G->e));
	printf("输入各顶点值：");
	for (i = 0; i < (G->n); i++) {
		scanf(" %c", &(G->adjlist[i].vextex));
		G->adjlist[i].firstedge = NULL;
	}
	printf("输入各条边：\n");
	for (k = 0; k < (G->e); k++) {
		scanf("%d,%d", &i, &j);
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = s;
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = i;
		s->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = s;
	}
}



//Create MatrixGraph
void CreateGraph(MyGraph *g) {
	int i, j, k;
	printf("请输入顶点n，边数e：");
	scanf("%d,%d", &(g->n), &(g->e));
	for (i = 0; i<(g->n); i++) {
		for (j = 0; j<(g->n); j++) {
			g->edges[i][j] = 0;
		}
	}

	printf("请输入图的边（从\"1\"开始计数）:\n");
	for (k = 0; k<(g->e); k++) {
		scanf("%d,%d", &i, &j);
		g->edges[i - 1][j - 1] = 1;
		g->edges[j - 1][i - 1] = 1;
	}

}

//Print
void outgraph(MyGraph *g) {
	int i, j;
	for (i = 0; i<(g->n); i++) {
		for (j = 0; j<(g->n); j++) {
			printf("%3d", g->edges[i][j]);
		}
		printf("\n");
	}
}

void print(ALGraph G) {
	int i;
	EdgeNode *p;
	for (i = 0; i < G.n; i++) {
		printf("\n%c-->", G.adjlist[i].vextex);
		p = G.adjlist[i].firstedge;
		while (p!=NULL)
		{
			printf("%3d", p->adjvex);
			p = p->next;
		}
	}
}

//Deep Search
void DFS(MyGraph *g, int i) {
	int j;
	printf("%3d", i+1);
	visited[i] = TRUE;
	for (j = 0; j < (g->n); j++) {
		if ((g->edges[i][j]) == 1 && !visited[j]) {
			DFS(g, j);
		}
	}
}

void DFSTraverse(MyGraph *g) {
	int i;
	for (i = 0; i < (g->n); i++) {
		visited[i] = FALSE;
	}
	for (i = 0; i < (g->n); i++) {
		if (!visited[i]) {
			DFS(g, i);
		}
	}
}

//Broad Search
void BFS(ALGraph *G, int k) {
	EdgeNode *p;
	int i, Q[MAX], front, rear;
	front = rear = 0;
	printf("%c", G->adjlist[k].vextex);
	visited[k] = TRUE;
	rear = (rear + 1) % MAX;
	Q[rear] = k;
	while (front != rear) {
		front = (front + 1) % MAX;
		i = Q[front];
		p = G->adjlist[i].firstedge;
		while (p) {
			if (!visited[p->adjvex]) {
				printf(" %c", G->adjlist[p->adjvex].vextex);
				visited[p->adjvex] = TRUE;
				rear = (rear + 1) % MAX;
				Q[rear] = p->adjvex;
			}
			p = p->next;
		}
	}
}



int main() {
	MyGraph mg;
	printf("用邻接矩阵创建图");
	CreateGraph(&mg);
	printf("邻接矩阵为：\n");
	outgraph(&mg);

	printf("深度优先遍历：\n");
	DFSTraverse(&mg);

	ALGraph G;
	int v;
	printf("创建邻接表\n");
	CreateALGraph(&G);
	printf("邻接表为：");
	print(G);
	for (v = 0; v < G.n; v++) {
		visited[v] = FALSE;
	}
	printf("\n广度优先遍历为：");
	for (v = 0; v < G.n; v++) {
		if (!visited[v]) {
			BFS(&G, v);
		}
	}

	system("pause");
	//return 0;
}