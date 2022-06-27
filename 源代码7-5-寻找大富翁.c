#include <stdio.h>

#define MAXM 10
typedef int ElementType;

void InsertionSort ( ElementType A[ ], int N )
{	/* �������� */
	int i, j ;
	ElementType temp;

	for ( i = 1; i < N; i++ ) {
		temp = A[i]; /* ȡ��δ���������еĵ�һ��Ԫ��*/
	    for ( j = i; (j > 0) && (temp > A[j-1]); j-- )
			A[ j ] = A[ j - 1 ]; /*������������������Ԫ�رȽϲ�����*/
		A[j] = temp; /* �Ž����ʵ�λ�� */
	}
}

void Adjust( ElementType A[], int i, int N )
{	/* ��A[]�е�ǰN��Ԫ�شӵ�i��Ԫ�ؿ�ʼ����Ǩ�Ƶ��� */
	int Child;
	ElementType temp;

	for( temp = A[i]; (2*i + 1) < N; i = Child){
		Child = (2*i + 1);  /* ���ӽڵ� */
		if ( (Child != N-1) && A[Child + 1] < A[Child])
			Child++; /* Childָ�������ӽ��Ľ�С�� */
		if( temp > A[Child] )
			A[i] = A[Child];  /* �ƶ�ChildԪ�ص��ϲ� */
		else	break;
	}
	A[i] = temp;    /*��temp�ŵ���ǰλ�á�*/
}

int main()
{
	int N, M, i;
	ElementType A[MAXM], temp;

	scanf("%d %d", &N, &M);
	if ( N > MAXM ) {
		for (i=0; i<M; i++)
			scanf("%d", &A[i]);
		/* ������С�� */
		for( i=(M-1)>>1; i>=0; i-- )
			Adjust(A, i, M);
		for (i=M; i<N; i++) {
			scanf("%d", &temp);  /* ����ʣ�µ�����   */
			if (temp > A[0]) {   /* ��������ݱȽϴ� */
				A[0] = temp;     /* �������滻��СԪ */
				Adjust(A, 0, M); /* ������С��       */
			}
		}
		/* �Զ��е�M�����ݽ��ж����� */
		for( i = M-1; i > 0; i-- ){
			/* ���Ѷ�Ԫ��A[0]�뵱ǰ�ѵ����һ��Ԫ��A[i]��λ */
			temp = A[0]; A[0] = A[i]; A[i] = temp;
			/* ����i��Ԫ�ص��¶ѴӸ�������¹��˵��� */
			Adjust(A, 0, i);
		}
	}
	else { /* ���N̫С�����ò������� */
		for (i=0; i<N; i++)
			scanf("%d", &A[i]);
		InsertionSort(A, N);
	}
	/* ������ */
	if (N < M) M = N; /* ���N��С�������ǰN�� */
	printf("%d", A[0]);
	for (i=1; i<M; i++)
		printf(" %d", A[i]);
	printf("\n");

	return 0;
}

