#include <stdio.h>

#define MAXM 51

int main()
{
	int N, Count[MAXM], i, K;

	/* 初始化Count[] */
	for (i=0; i<MAXM; i++) Count[i] = 0;

	scanf("%d", &N);
	for (i=0; i<N; i++) {
		scanf("%d", &K);
		Count[K]++; /* 工龄为K的计数器加1 */
	}
	for (K=0; K<MAXM; K++)
		if (Count[K])
			printf("%d:%d\n", K, Count[K]);

	return 0;
}

