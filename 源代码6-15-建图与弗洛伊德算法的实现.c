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
			Graph->G[V][W] = INFINITY;
			
	return Graph; 
}
       
void InsertEdge( MGraph Graph, Edge E )
{
     /* ����� <V1, V2> */
     Graph->G[E->V1][E->V2] = E->Weight;    
     /* ��������ͼ����Ҫ�����<V2, V1> */
     Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, i;
	
	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */ 
	
	scanf("%d", &(Graph->Ne));   /* ������� */
	if ( Graph->Ne != 0 ) { /* ����б� */ 
	    E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */ 
	    /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			E->V1--; E->V2--; /* �����Ŵ�1��ʼ */
            InsertEdge( Graph, E );
        }
	}
	return Graph;
} 

void Floyd( MGraph Graph, WeightType D[][MaxVertexNum] )
{
	Vertex i, j, k;

	/* ��ʼ�� */
	for ( i=0; i<Graph->Nv; i++ )
		for( j=0; j<Graph->Nv; j++ )
			D[i][j] = Graph->G[i][j];

	for( k=0; k<Graph->Nv; k++ )
		for( i=0; i<Graph->Nv; i++ )
			for( j=0; j<Graph->Nv; j++ )
				if( D[i][k] + D[k][j] < D[i][j] )
					D[i][j] = D[i][k] + D[k][j];
}

