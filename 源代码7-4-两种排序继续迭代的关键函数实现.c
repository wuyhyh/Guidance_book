void PrintResults( int *B, int N )
{
	int i;
	
	printf("%d", B[0]);
	for ( i=1; i<N; i++ ) printf(" %d", B[i]);
	printf("\n");
}

void NextInsertion( int *B, int N, int K )
{
	int i, tmp;

	printf("Insertion Sort\n");
	tmp = B[K];
	for ( i=K-1; i>=0; i-- )
		if ( tmp < B[i] ) B[i+1] = B[i];
		else break;
	B[i+1] = tmp;
	PrintResults(B, N);
}

int MergeLength( int *B, int N )
{
	int i, l;
	
	for ( l=2; l<=N; l*=2 ) {
		for ( i=l; i<N; i+=(l+l) )
			if (B[i-1] > B[i]) break;
		if ( i < N ) break;
	}
	return l;
}

void NextMerge( int *B, int N )
{
	int i, p1, p2, p, L;
	int *Tmp;

	Tmp = (int *)malloc(sizeof(int) * N);
	printf("Merge Sort\n");
	/* 找出当前归并段长度 */
	L = MergeLength(B, N);
	/* 开始归并 */
	p = 0; /* p指向Tmp中当前处理的位置 */
	for ( i=0; i<(N-L-L); i+=(L+L) ) { /* 两两归并长度为L的段 */
		p1 = i; p2 = i+L; /* p1和p2分别指向两个段的当前处理位置 */ 
		while ( (p1<(i+L)) && (p2<(i+L+L)) ) {
			if ( B[p1] > B[p2] ) Tmp[p++] = B[p2++];
			else Tmp[p++] = B[p1++];
		}
		while ( p1<(i+L) )   Tmp[p++] = B[p1++];
		while ( p2<(i+L+L) ) Tmp[p++] = B[p2++];
	}
	if ( (N-i)>L ) { /* 如果最后剩2段，执行归并 */
		p1 = i; p2 = i+L;
		while ( (p1<(i+L)) && (p2<N) ) {
			if ( B[p1] > B[p2]) Tmp[p++] = B[p2++];
			else Tmp[p++] = B[p1++];
		}
		while ( p1<(i+L) ) Tmp[p++] = B[p1++];
		while ( p2<N )     Tmp[p++] = B[p2++];
	}
	else /* 最后只剩1段 */
		while ( i < N ) Tmp[i] = B[i++];
	PrintResults(Tmp, N);
}

