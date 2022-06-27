void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
		Queue Q; 	
		Vertex V;
		PtrToAdjVNode W;
	
		Q = CreateQueue( MaxVertexNum );
		Visit( S );
		Visited[S] = true;
	    AddQ(Q, S);
	    
		while ( !IsEmpty(Q) ) {
			V = DeleteQ(Q);
			for( W=Graph->G[V].FirstEdge; W; W=W->Next )
				if ( !Visited[W->AdjV] ) {
					Visit( W->AdjV );
					Visited[W->AdjV] = true;
	                AddQ(Q, W->AdjV);
				}
		} /* while½áÊø*/
}

