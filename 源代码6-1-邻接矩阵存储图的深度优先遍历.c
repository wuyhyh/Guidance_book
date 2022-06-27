void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
	Vertex W;
	
	Visit( V ); /* 首先访问当前顶点 */
	Visited[V] = true;

	for( W=0; W<Graph->Nv; W++ )
        /* 当W尚未被访问且与V右边相连 */
		if ( !Visited[W] && (Graph->G[V][W]<INFINITY) )
			DFS( Graph, W, Visit );
}

