#include<stdio.h>
#include<stdlib.h>

/*-----图的定义 -----*/
#define MaxVertexNum 100	/* 最大顶点数设为100 */
#define INFINITY 65535		/* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;		/* 边的权值设为整型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;
       
/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
/*-----图的定义结束 -----*/

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

