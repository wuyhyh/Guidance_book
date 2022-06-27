#include <stdio.h>

#define MAXN 100000

int main()
{
	int i, Tmp, Next, N, Cnt, flag;
	int A[MAXN], T[MAXN];
	
	scanf("%d", &N);
	for ( i=0; i<N; i++ ) {
		scanf("%d", &A[i]);
		T[A[i]] = i; /* 初始化表 */
	}
	Cnt = 0;
	for ( i=0; i<N; i++ ) {
		if ( T[i] == i ) continue; /* 位置正确，则不处理 */
		flag = 0;
		Tmp = T[i]; /* 将第i个元素临时存放，相当于把0换到环里 */
		T[i] = i; /* 标识环的结束 */
		Cnt++; /* 初始有1个元素 */
		if ( Tmp == 0 ) flag = 1; /* 如果0在环中，则标记一下 */
		while ( Tmp != T[Tmp] ) { /* 当环没有结束 */
			/* 执行一次与0交换 */ 
			Next = T[Tmp]; 
			T[Tmp] = Tmp;
			Tmp = Next;
			if ( Tmp == 0 ) flag = 1; /* 如果0在环中，则标记一下 */
			Cnt++; /* 计数1次 */
		}
		if ( flag ) Cnt--; /* 如果0在环中，则为元素个数减1 */
		else Cnt++; /* 否则为元素个数加1 */
	}
	printf("%d\n", Cnt);

	return 0;
}

