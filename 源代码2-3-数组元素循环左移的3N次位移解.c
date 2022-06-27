#include <stdio.h>

#define MAXN 100
#define Swap(a,b)  a ^= b, b ^= a, a ^= b;
/* ͨ����������������㽻��a��b */

void LeftShift( int Array[], int N, int M );

int main()
{
	int Number[MAXN], N, M;
	int i;

	scanf("%d %d", &N, &M);
	for( i=0; i<N; i++ )		    
		scanf("%d", &Number[i] );
	M %= N;	/* ��M���ڵ���Nʱת���ɵȼ۵�С��N���� */
	LeftShift(Number, N, M);		/* ѭ������Mλ��*/
    printf("%d", Number[0]); /* ��ӡ��� */
	for( i=1; i<N; i++ )
		printf(" %d", Number[i]);
	printf("\n");

    return 0;
}

void LeftShift( int Array[], int N, int M )
{   
	int i, j;

	if( M>0 && M<N ){
		for(i=0, j=N-1; i<j; i++, j--)	/* ��תN������ */
			Swap(Array[i], Array[j]);
		for(i=0, j=N-M-1; i<j; i++, j--)	/* ��תǰN-M������ */
			Swap(Array[i], Array[j]);
		for(i=N-M, j=N-1; i<j; i++, j--)	/* ��ת��M������ */
			Swap(Array[i], Array[j]);
	}
}

