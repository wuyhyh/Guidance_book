int IsInsertion( int *A, int *B, int N )
{
	int i, k;

	for ( i=1; i<N; i++ )
		if (B[i] < B[i-1]) break; /* ����˳�򲻶� */ 
	k = i; /* �����ǲ����������������β��λ�� */
	for ( ; i<N; i++ )
		if ( B[i] != A[i] ) break; /* ���ֺ��������б仯 */ 
	if ( i == N ) return k; /* �ǲ������򣬷��ز���λ�� */
	else return 0; /* ���ǲ������� */
}

