LGraph CreateGraph( int VertexNum )
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V;
	LGraph Graph;
    
    Graph = (LGraph)malloc( sizeof(struct GNode) ); /* 建立图 */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接表头指针 */
   	for (V=0; V<Graph->Nv; V++) {
	   	Visited[V] = false; 
		Graph->G[V].FirstEdge = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); 
		Graph->G[V].FirstEdge->Next = NULL; /* 建链表空头结点 */
	}
			
	return Graph; 
}
       
void InsertEdge( LGraph Graph, Edge E )
{
    PtrToAdjVNode NewNode, p;
    
    /* 插入边 <V1, V2> */
    /* 为V2建立新的邻接点 */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2; NewNode->Next = NULL;
	/* 将V2插入V1的链表合适位置 */
	p = Graph->G[E->V1].FirstEdge;
	while (p->Next && (p->Next->AdjV < NewNode->AdjV))
		p = p->Next;
	NewNode->Next = p->Next;
	p->Next = NewNode;
		
    /* 为V1建立新的邻接点 */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1; NewNode->Next = NULL;
	/* 将V1插入V2的链表合适位置 */
	p = Graph->G[E->V2].FirstEdge;
	while (p->Next && (p->Next->AdjV < NewNode->AdjV))
		p = p->Next;
	NewNode->Next = p->Next;
	p->Next = NewNode;
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */ 
	
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	scanf("%d", &(Graph->S));    /* 读入起点 */
	Graph->S--; /* 输入编号从1开始 */
	if ( Graph->Ne != 0 ) { /* 如果有边 */ 
	    E = (Edge)malloc( sizeof(struct ENode) ); /* 建立边结点 */ 
	    /* 读入边，格式为"起点 终点"，插入邻接表 */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d", &E->V1, &E->V2); 
		    E->V1--; E->V2--; /* 输入编号从1开始 */
            InsertEdge( Graph, E );
		}
	} 
	return Graph;
}

