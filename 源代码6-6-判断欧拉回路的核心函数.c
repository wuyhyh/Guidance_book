void DFS( MGraph Graph, Vertex V )
{
	Vertex W;
	
	Visited[V] = true;
	for( W=0; W<Graph->Nv; W++ )
        /* ��W��δ����������V�ұ����� */
		if ( !Visited[W] && (Graph->G[V][W]) )
			DFS( Graph, W );
}

bool CheckG ( MGraph Graph )
{ /* ��鶥��Ķ��Ƿ�ȫΪż�� */
	Vertex V;

	for ( V=0; V<Graph->Nv; V++ ) 
		if ( Graph->Degree[V] %2 ) return false; /* ���������ȵı��򷵻�0 */
	return true; /* ȫ��ż���ȵı��򷵻�1 */
}

