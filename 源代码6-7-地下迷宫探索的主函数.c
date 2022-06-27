#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true } bool;

/*----图的邻接表表示法----*/
#define MaxVertexNum 1000	/* 最大顶点数设为1000 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
	Vertex AdjV;		/* 邻接点下标 */
	PtrToAdjVNode Next;	/* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;/* 边表头指针 */
} AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{  
	int Nv;     /* 顶点数 */
	int Ne;     /* 边数   */
	AdjList G;  /* 邻接表 */
	Vertex S;   /* 探索起点 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */
bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph( int VertexNum );
void InsertEdge( LGraph Graph, Edge E );
LGraph BuildGraph();
/*------图的定义结束-------*/

/*------堆栈的定义-------*/
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
/*----堆栈的定义结束-----*/

void NonRec_DFS( LGraph Graph, Vertex V );

int main()
{
	Vertex V;
	LGraph Graph = BuildGraph();

	NonRec_DFS( Graph, Graph->S );
	for ( V=0; V<Graph->Nv; V++ )
		if ( !Visited[V] ) break;
	if ( V<Graph->Nv )    /* 若有结点没被DFS访问到 */
		printf(" 0\n");  /* 则图不连通 */
	else printf("\n");
	
	return 0;
}

