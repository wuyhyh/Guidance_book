void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
	Vertex W;
	
	Visit( V ); /* ���ȷ��ʵ�ǰ���� */
	Visited[V] = true;

	for( W=0; W<Graph->Nv; W++ )
        /* ��W��δ����������V�ұ����� */
		if ( !Visited[W] && (Graph->G[V][W]<INFINITY) )
			DFS( Graph, W, Visit );
}

