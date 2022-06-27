MGraph CreateGraph( int VertexNum )
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
	MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	for (V=0; V<Graph->Nv; V++)
		for (W=0; W<Graph->Nv; W++)  
			Graph->G[V][W] = INFINITY;
			
	return Graph; 
}
       
void InsertEdge( MGraph Graph, Edge E )
{
     /* 插入边 <V1, V2> */
     Graph->G[E->V1][E->V2] = E->Weight;    
     /* 若是无向图，还要插入边<V2, V1> */
     Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i;
	
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */ 
	
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if ( Graph->Ne != 0 ) { /* 如果有边 */ 
	    E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */ 
	    /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			E->V1--; E->V2--; /* 输入编号从1开始 */
            InsertEdge( Graph, E );
        }
	}
	return Graph;
} 

void Floyd( MGraph Graph, WeightType D[][MaxVertexNum] )
{
	Vertex i, j, k;

	/* 初始化 */
	for ( i=0; i<Graph->Nv; i++ )
		for( j=0; j<Graph->Nv; j++ )
			D[i][j] = Graph->G[i][j];

	for( k=0; k<Graph->Nv; k++ )
		for( i=0; i<Graph->Nv; i++ )
			for( j=0; j<Graph->Nv; j++ )
				if( D[i][k] + D[k][j] < D[i][j] )
					D[i][j] = D[i][k] + D[k][j];
}

