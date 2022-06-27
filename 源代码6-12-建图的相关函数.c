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
			Graph->Dist[V][W] = Graph->Cost[V][W] = INFINITY;
			
	return Graph; 
}
       
void InsertEdge( MGraph Graph, Edge E )
{
     /* 插入边 <V1, V2> */
     Graph->Dist[E->V1][E->V2] = E->Dist;    
     Graph->Cost[E->V1][E->V2] = E->Cost;    
     /* 若是无向图，还要插入边<V2, V1> */
     Graph->Dist[E->V2][E->V1] = E->Dist;
     Graph->Cost[E->V2][E->V1] = E->Cost;
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
	scanf("%d %d", &(Graph->S), &(Graph->D)); /* 读入起点、终点 */
	if ( Graph->Ne != 0 ) { /* 如果有边 */ 
	    E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */ 
	    /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d %d %d", &E->V1, &E->V2, &E->Dist, &E->Cost ); 
            InsertEdge( Graph, E );
        }
	} 
	return Graph;
}

