void DFS( MGraph Graph, Vertex V )
{
	Vertex W;
	
	Visited[V] = true;
	for( W=0; W<Graph->Nv; W++ )
        /* 当W尚未被访问且与V右边相连 */
		if ( !Visited[W] && (Graph->G[V][W]) )
			DFS( Graph, W );
}

bool CheckG ( MGraph Graph )
{ /* 检查顶点的度是否全为偶数 */
	Vertex V;

	for ( V=0; V<Graph->Nv; V++ ) 
		if ( Graph->Degree[V] %2 ) return false; /* 发现奇数度的边则返回0 */
	return true; /* 全是偶数度的边则返回1 */
}

