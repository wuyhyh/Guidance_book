bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 )
{ /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
	Vertex Root1, Root2;

	Root1 = Find( VSet, V1 ); /* 得到V1所属的连通集名称 */
	Root2 = Find( VSet, V2 ); /* 得到V2所属的连通集名称 */

	if( Root1==Root2 ) /* 若V1和V2已经连通，则该边不能要 */
		return false;
	else { /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
		Union( VSet, Root1, Root2 );
		return true;
	}
}

int Kruskal( LGraph Graph )
{ /* 返回最小生成树权重和 */
	WeightType TotalWeight;
    int ECount, NextEdge;
	SetType VSet; /* 顶点数组 */
	Edge ESet;    /* 边数组 */

	InitializeVSet( VSet, Graph->Nv ); /* 初始化顶点并查集 */
	ESet = (Edge)malloc( sizeof(struct ENode)*Graph->Ne );
	InitializeESet( Graph, ESet ); /* 初始化边的最小堆 */
    TotalWeight = 0; /* 初始化权重和     */
    ECount = 0;      /* 初始化收录的边数 */

	NextEdge = Graph->Ne; /* 原始边集的规模 */
	while ( ECount < Graph->Nv-1 ) {  /* 当收集的边不足以构成树时 */
        /* 从边集中得到最小边的位置 */
		NextEdge = GetEdge( ESet, NextEdge ); 
		if (NextEdge < 0) /* 边集已空 */
			break;
        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
		if ( CheckCycle( VSet, ESet[NextEdge].V1, ESet[NextEdge].V2 ) == true ) {
			TotalWeight += ESet[NextEdge].Weight; /* 累计权重 */
			ECount++; /* 生成树中边数加1 */
		}
	}
	if ( ECount < Graph->Nv-1 )
		TotalWeight = -1; /* 设置错误标记，表示生成树不存在 */

	return TotalWeight;
}

