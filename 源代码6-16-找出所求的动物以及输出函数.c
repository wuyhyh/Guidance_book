WeightType FindMaxDist( WeightType D[][MaxVertexNum], Vertex i, int N )
{ /* �ҳ�i���������������� */
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
		if ( MaxDist == INFINITY ) { /* ˵���д�i�޷�����Ķ��� */
			printf("0\n");
			return;
		}
		if ( MinDist > MaxDist ) { /* �ҵ�������С�Ķ��� */
			MinDist = MaxDist;  Animal = i+1; /* ���¾��룬��¼��� */
		}
	}
	printf("%d %d\n", Animal, MinDist);
}

