#include<stdio.h>
#include<stdlib.h>
typedef enum {false, true} bool;

/*------ ͼ�Ķ��� ------*/
#define MaxVertexNum 1000	/* ��󶥵�����Ϊ1000 */
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;		/* �ߵ�Ȩֵ��Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
    WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
	Vertex AdjV;		/* �ڽӵ��±� */
	WeightType Weight;  /* ��Ȩ�� */
	PtrToAdjVNode Next;	/* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;/* �߱�ͷָ�� */
} AdjList[MaxVertexNum];    /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
	int Nv;     /* ������ */
	int Ne;     /* ����   */
	AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

LGraph CreateGraph( int VertexNum );
void InsertEdge( LGraph Graph, Edge E );
LGraph BuildGraph();
/*------ ͼ�Ķ������ ------*/

/*------ ��С����ض��� ------*/
typedef struct ENode Elm;

void Swap( Elm *a, Elm *b );
void PercDown( Edge ESet, int p, int N );
void InitializeESet( LGraph Graph, Edge ESet );
int GetEdge( Edge ESet, int CurrentSize );
/*------ ��С����ض������ ------*/

/*------ ���ڶ���Ĳ��鼯 ------*/
typedef Vertex ElementType; /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
typedef Vertex SetName;     /* Ĭ���ø������±���Ϊ�������� */
typedef ElementType SetType[MaxVertexNum]; /* ���輯��Ԫ���±��0��ʼ */

void InitializeVSet( SetType S, int N );
void Union( SetType S, SetName Root1, SetName Root2 );
SetName Find( SetType S, ElementType X );
/*------ ���鼯������� ------*/

bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 );
int Kruskal( LGraph Graph );

int main()
{
	LGraph G = BuildGraph();
	printf("%d\n", Kruskal( G ));
	return 0;
}

