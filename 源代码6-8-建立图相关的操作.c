LGraph CreateGraph( int VertexNum )
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
    Vertex V;
	LGraph Graph;
    
    Graph = (LGraph)malloc( sizeof(struct GNode) ); /* ����ͼ */
	Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* ��ʼ���ڽӱ�ͷָ�� */
   	for (V=0; V<Graph->Nv; V++) {
	   	Visited[V] = false; 
		Graph->G[V].FirstEdge = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); 
		Graph->G[V].FirstEdge->Next = NULL; /* �������ͷ��� */
	}
			
	return Graph; 
}
       
void InsertEdge( LGraph Graph, Edge E )
{
    PtrToAdjVNode NewNode, p;
    
    /* ����� <V1, V2> */
    /* ΪV2�����µ��ڽӵ� */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2; NewNode->Next = NULL;
	/* ��V2����V1���������λ�� */
	p = Graph->G[E->V1].FirstEdge;
	while (p->Next && (p->Next->AdjV < NewNode->AdjV))
		p = p->Next;
	NewNode->Next = p->Next;
	p->Next = NewNode;
		
    /* ΪV1�����µ��ڽӵ� */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1; NewNode->Next = NULL;
	/* ��V1����V2���������λ�� */
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
	
	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */ 
	
	scanf("%d", &(Graph->Ne));   /* ������� */
	scanf("%d", &(Graph->S));    /* ������� */
	Graph->S--; /* �����Ŵ�1��ʼ */
	if ( Graph->Ne != 0 ) { /* ����б� */ 
	    E = (Edge)malloc( sizeof(struct ENode) ); /* �����߽�� */ 
	    /* ����ߣ���ʽΪ"��� �յ�"�������ڽӱ� */
	    for (i=0; i<Graph->Ne; i++) {
		    scanf("%d %d", &E->V1, &E->V2); 
		    E->V1--; E->V2--; /* �����Ŵ�1��ʼ */
            InsertEdge( Graph, E );
		}
	} 
	return Graph;
}

