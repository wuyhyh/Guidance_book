MGraph CreateGraph( int VertexNum )
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
	MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V=0; V<Graph->Nv; V++) {
		Graph->Degree[V] = 0;
		for (W=0; W<Graph->Nv; W++)  
			Graph->G[V][W] = 0;
	}
			
	return Graph; 
}
       
void InsertEdge( MGraph Graph, Edge E )
{
     /* 插入边 <V1, V2> */
     Graph->G[E->V1][E->V2] = 1;
     Graph->Degree[E->V1]++;
     /* 若是无向图，还要插入边<V2, V1> */
     Graph->G[E->V2][E->V1] = 1;
     Graph->Degree[E->V2]++;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */ 
	
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if ( Graph->Ne != 0 ) { /* 如果有边 */ 
	    E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */ 
	    /* 读入边，格式为"起点 终点"，插入邻接矩阵 */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d", &E->V1, &E->V2); 
		    E->V1--; E->V2--; /* 输入的编号从1开始 */
            InsertEdge( Graph, E );
        }
	} 
	return Graph;
}

