#include<stdio.h>
#include<stdlib.h>
typedef enum {false, true} bool;

/*------ 图的定义 ------*/
#define MaxVertexNum 1000	/* 最大顶点数设为1000 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;		/* 边的权值设为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
	Vertex AdjV;		/* 邻接点下标 */
	WeightType Weight;  /* 边权重 */
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
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph( int VertexNum );
void InsertEdge( LGraph Graph, Edge E );
LGraph BuildGraph();
/*------ 图的定义结束 ------*/

/*------ 最小堆相关定义 ------*/
typedef struct ENode Elm;

void Swap( Elm *a, Elm *b );
void PercDown( Edge ESet, int p, int N );
void InitializeESet( LGraph Graph, Edge ESet );
int GetEdge( Edge ESet, int CurrentSize );
/*------ 最小堆相关定义结束 ------*/

/*------ 关于顶点的并查集 ------*/
typedef Vertex ElementType; /* 默认元素可以用非负整数表示 */
typedef Vertex SetName;     /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MaxVertexNum]; /* 假设集合元素下标从0开始 */

void InitializeVSet( SetType S, int N );
void Union( SetType S, SetName Root1, SetName Root2 );
SetName Find( SetType S, ElementType X );
/*------ 并查集定义结束 ------*/

bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 );
int Kruskal( LGraph Graph );

int main()
{
	LGraph G = BuildGraph();
	printf("%d\n", Kruskal( G ));
	return 0;
}

