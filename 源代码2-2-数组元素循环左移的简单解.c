#include <stdio.h>

#define MAXN 100

void Shift( int Array[], int N );

int main()
{
	int Number[MAXN], N, M;
	int i;

	scanf("%d%d", &N, &M);
	for( i=0; i<N; i++ )
		scanf("%d", &Number[i] );
	M %= N;	/* ��M���ڵ���Nʱת���ɵȼ۵�С��N������*/
	for( i=0; i< M; i++ )
		Shift(Number, N);     /* N��Ԫ��ѭ��λ��1λ */
	for( i=0; i<N-1; i++ )   /* ��ӡ��� */
		printf("%d ", Number[i]);
	printf("%d\n", Number[N-1]);
	return 0;
}

void Shift( int Array[], int N )
{
	int i, ArrayHead;

	ArrayHead = Array[0];
	for( i=0; i<N-1; i++ )			/* N��Ԫ��ѭ��λ��1λ */
		Array[i] = Array[i+1];
	Array[N-1] = ArrayHead;
}

