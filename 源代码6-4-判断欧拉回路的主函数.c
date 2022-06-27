#include<stdio.h>
#include<stdlib.h>
typedef enum {false, true} bool;

/* ͼ���ڽӾ����ʾ�� */
#define MaxVertexNum 1000	/* ��󶥵�����Ϊ1000 */
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
};
typedef PtrToENode Edge;
       
/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
	int Degree[MaxVertexNum];      /* �涥��Ķ� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

MGraph CreateGraph( int VertexNum );
void InsertEdge( MGraph Graph, Edge E );
MGraph BuildGraph();
void DFS( MGraph Graph, Vertex V );
bool CheckG ( MGraph Graph );

int main()
{
	Vertex V;
	MGraph Graph = BuildGraph();
	DFS( Graph, 0 ); /* �����ͨ�� */
	for ( V=0; V<Graph->Nv; V++ )
		if (!Visited[V]) break;
	if ( V<Graph->Nv ) /* ���н��û��DFS���ʵ� */
		printf("0\n");  /* ��ͼ����ͨ */
	else /* ��ͼ��ͨ */
		printf("%d\n", CheckG(Graph));
	return 0;
}

