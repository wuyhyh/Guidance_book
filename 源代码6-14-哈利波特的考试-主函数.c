#include<stdio.h>
#include<stdlib.h>

/*-----ͼ�Ķ��� -----*/
#define MaxVertexNum 100	/* ��󶥵�����Ϊ100 */
#define INFINITY 65535		/* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;
       
/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */
/*-----ͼ�Ķ������ -----*/

MGraph CreateGraph( int VertexNum );
void InsertEdge( MGraph Graph, Edge E );
MGraph BuildGraph();
void Floyd( MGraph Graph, WeightType D[][MaxVertexNum] );

WeightType FindMaxDist( WeightType D[][MaxVertexNum], Vertex i, int N );
void FindAnimal( MGraph Graph );

int main()
{
	MGraph G = BuildGraph();
	FindAnimal( G );
	return 0;
}

