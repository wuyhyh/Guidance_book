#include<stdio.h>
#include<stdlib.h>
typedef enum { false, true } bool;

/* 图的邻接矩阵表示法 */
#define MaxVertexNum 500	/* 最大顶点数设为500 */
#define INFINITY 65535		/* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;		/* 边的权值设为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Dist, Cost;  /* 权重 */
};
typedef PtrToENode Edge;
       
/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType Dist[MaxVertexNum][MaxVertexNum]; /* 距离 */
	WeightType Cost[MaxVertexNum][MaxVertexNum]; /* 费用 */
	Vertex S, D; /* 起点、终点 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */

MGraph CreateGraph( int VertexNum );
void InsertEdge( MGraph Graph, Edge E );
MGraph BuildGraph();

/* 邻接矩阵存储 - 有权图的单源最短路算法 */
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

