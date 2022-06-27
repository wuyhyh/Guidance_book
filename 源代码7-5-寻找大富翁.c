#include <stdio.h>

#define MAXM 10
typedef int ElementType;

void InsertionSort ( ElementType A[ ], int N )
{	/* 插入排序 */
	int i, j ;
	ElementType temp;

	for ( i = 1; i < N; i++ ) {
		temp = A[i]; /* 取出未排序序列中的第一个元素*/
	    for ( j = i; (j > 0) && (temp > A[j-1]); j-- )
			A[ j ] = A[ j - 1 ]; /*依次与已排序序列中元素比较并右移*/
		A[j] = temp; /* 放进合适的位置 */
	}
}

void Adjust( ElementType A[], int i, int N )
{	/* 对A[]中的前N个元素从第i个元素开始向下迁移调整 */
	int Child;
	ElementType temp;

	for( temp = A[i]; (2*i + 1) < N; i = Child){
		Child = (2*i + 1);  /* 左孩子节点 */
		if ( (Child != N-1) && A[Child + 1] < A[Child])
			Child++; /* Child指向左右子结点的较小者 */
		if( temp > A[Child] )
			A[i] = A[Child];  /* 移动Child元素到上层 */
		else	break;
	}
	A[i] = temp;    /*将temp放到当前位置　*/
}

int main()
{
	int N, M, i;
	ElementType A[MAXM], temp;

	scanf("%d %d", &N, &M);
	if ( N > MAXM ) {
		for (i=0; i<M; i++)
			scanf("%d", &A[i]);
		/* 建立最小堆 */
		for( i=(M-1)>>1; i>=0; i-- )
			Adjust(A, i, M);
		for (i=M; i<N; i++) {
			scanf("%d", &temp);  /* 读入剩下的数据   */
			if (temp > A[0]) {   /* 如果新数据比较大 */
				A[0] = temp;     /* 新数据替换最小元 */
				Adjust(A, 0, M); /* 调整最小堆       */
			}
		}
		/* 对堆中的M个数据进行堆排序 */
		for( i = M-1; i > 0; i-- ){
			/* 将堆顶元素A[0]与当前堆的最后一个元素A[i]换位 */
			temp = A[0]; A[0] = A[i]; A[i] = temp;
			/* 将有i个元素的新堆从根结点向下过滤调整 */
			Adjust(A, 0, i);
		}
	}
	else { /* 如果N太小，则用插入排序 */
		for (i=0; i<N; i++)
			scanf("%d", &A[i]);
		InsertionSort(A, N);
	}
	/* 输出结果 */
	if (N < M) M = N; /* 如果N更小，则输出前N个 */
	printf("%d", A[0]);
	for (i=1; i<M; i++)
		printf(" %d", A[i]);
	printf("\n");

	return 0;
}

