int IsInsertion( int *A, int *B, int N )
{
	int i, k;

	for ( i=1; i<N; i++ )
		if (B[i] < B[i-1]) break; /* 发现顺序不对 */ 
	k = i; /* 可能是插入排序的有序序列尾部位置 */
	for ( ; i<N; i++ )
		if ( B[i] != A[i] ) break; /* 发现后面序列有变化 */ 
	if ( i == N ) return k; /* 是插入排序，返回插入位置 */
	else return 0; /* 不是插入排序 */
}

