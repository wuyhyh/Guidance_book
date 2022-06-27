MGraph CreateGraph( int VertexNum )
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V, W;
	MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	for (V=0; V<Graph->Nv; V++)
		for (W=0; W<Graph->Nv; W++)  
			Graph->Dist[V][W] = Graph->Cost[V][W] = INFINITY;
			
	return Graph; 
}
       
void InsertEdge( MGraph Graph, Edge E )
{
     /* ����� <V1, V2> */
     Graph->Dist[E->V1][E->V2] = E->Dist;    
     Graph->Cost[E->V1][E->V2] = E->Cost;    
     /* ��������ͼ����Ҫ�����<V2, V1> */
     Graph->Dist[E->V2][E->V1] = E->Dist;
     Graph->Cost[E->V2][E->V1] = E->Cost;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */ 
	
	scanf("%d", &(Graph->Ne));   /* ������� */
	scanf("%d %d", &(Graph->S), &(Graph->D)); /* ������㡢�յ� */
	if ( Graph->Ne != 0 ) { /* ����б� */ 
	    E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */ 
	    /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d %d %d", &E->V1, &E->V2, &E->Dist, &E->Cost ); 
            InsertEdge( Graph, E );
        }
	} 
	return Graph;
}

