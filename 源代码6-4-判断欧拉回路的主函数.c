#include<stdio.h>
#include<stdlib.h>
typedef enum {false, true} bool;

/* 图的邻接矩阵表示法 */
#define MaxVertexNum 1000	/* 最大顶点数设为1000 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;		/* 边的权值设为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
};
typedef PtrToENode Edge;
       
/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
	int Degree[MaxVertexNum];      /* 存顶点的度 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

MGraph CreateGraph( int VertexNum );
void InsertEdge( MGraph Graph, Edge E );
MGraph BuildGraph();
void DFS( MGraph Graph, Vertex V );
bool CheckG ( MGraph Graph );

int main()
{
	Vertex V;
	MGraph Graph = BuildGraph();
	DFS( Graph, 0 ); /* 检查连通性 */
	for ( V=0; V<Graph->Nv; V++ )
		if (!Visited[V]) break;
	if ( V<Graph->Nv ) /* 若有结点没被DFS访问到 */
		printf("0\n");  /* 则图不连通 */
	else /* 若图连通 */
		printf("%d\n", CheckG(Graph));
	return 0;
}

