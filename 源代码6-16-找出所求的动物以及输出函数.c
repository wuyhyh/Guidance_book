WeightType FindMaxDist( WeightType D[][MaxVertexNum], Vertex i, int N )
{ /* 找出i到其他动物的最长距离 */
	WeightType MaxDist;
	Vertex j;

	MaxDist = 0;
	for( j=0; j<N; j++ )
		if ( i!=j && D[i][j]>MaxDist ) MaxDist = D[i][j];
	return MaxDist;
}

void FindAnimal( MGraph Graph )
{
	WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
	Vertex Animal, i;

	Floyd( Graph, D );

	MinDist = INFINITY;
	for ( i=0; i<Graph->Nv; i++ ) {
		MaxDist = FindMaxDist( D, i, Graph->Nv );
		if ( MaxDist == INFINITY ) { /* 说明有从i无法变出的动物 */
			printf("0\n");
			return;
		}
		if ( MinDist > MaxDist ) { /* 找到最长距离更小的动物 */
			MinDist = MaxDist;  Animal = i+1; /* 更新距离，记录编号 */
		}
	}
	printf("%d %d\n", Animal, MinDist);
}

