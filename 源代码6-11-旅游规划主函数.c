#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true } bool;

/* ͼ���ڽӾ����ʾ�� */
#define MaxVertexNum 500	/* ��󶥵�����Ϊ500 */
#define INFINITY 65535		/* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Dist, Cost;  /* Ȩ�� */
};
typedef PtrToENode Edge;
       
/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType Dist[MaxVertexNum][MaxVertexNum]; /* ���� */
	WeightType Cost[MaxVertexNum][MaxVertexNum]; /* ���� */
	Vertex S, D; /* ��㡢�յ� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */

MGraph CreateGraph( int VertexNum );
void InsertEdge( MGraph Graph, Edge E );
MGraph BuildGraph();

/* �ڽӾ���洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
#define ERROR -1
Vertex FindMinDist( MGraph Graph, int dist[], int collected[] );
void Dijkstra( MGraph Graph, int dist[], int cost[], Vertex S );

int main()
{
	int *dist, *cost;
	MGraph Graph = BuildGraph();
	dist = (int *)malloc(sizeof(int) * Graph->Nv);
	cost = (int *)malloc(sizeof(int) * Graph->Nv);
	Dijkstra( Graph, dist, cost, Graph->S );
	printf("%d %d\n", dist[Graph->D], cost[Graph->D]);

	return 0;
}

