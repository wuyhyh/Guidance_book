#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true } bool;

/*----ͼ���ڽӱ��ʾ��----*/
#define MaxVertexNum 1000	/* ��󶥵�����Ϊ1000 */
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* �����<V1, V2> */
};
typedef PtrToENode Edge;

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
	Vertex AdjV;		/* �ڽӵ��±� */
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
	Vertex S;   /* ̽����� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */
bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

LGraph CreateGraph( int VertexNum );
void InsertEdge( LGraph Graph, Edge E );
LGraph BuildGraph();
/*------ͼ�Ķ������-------*/

/*------��ջ�Ķ���-------*/
typedef Vertex ElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack();
bool IsEmpty( Stack S );
bool Push( Stack S, ElementType X );
ElementType Pop( Stack S );
ElementType Peek( Stack S );
/*----��ջ�Ķ������-----*/

void NonRec_DFS( LGraph Graph, Vertex V );

int main()
{
	Vertex V;
	LGraph Graph = BuildGraph();

	NonRec_DFS( Graph, Graph->S );
	for ( V=0; V<Graph->Nv; V++ )
		if ( !Visited[V] ) break;
	if ( V<Graph->Nv )    /* ���н��û��DFS���ʵ� */
		printf(" 0\n");  /* ��ͼ����ͨ */
	else printf("\n");
	
	return 0;
}

