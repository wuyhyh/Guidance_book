#include <stdio.h>
#include <stdlib.h>

int IsInsertion( int *A, int *B, int N ); /* 判断是否插入排序 */
void PrintResults( int *B, int N ); /* 输出结果序列 */
void NextInsertion( int *B, int N, int K ); /* 执行下一步插入 */
int MergeLength( int *B, int N ); /* 找出归并段长度 */
void NextMerge( int *B, int N ); /* 执行下一步归并 */

int main()
{
	int N, i, k;
	int *A, *B;

	scanf("%d", &N);
	A = (int *)malloc(sizeof(int) * N); /* A 存原始序列 */
	B = (int *)malloc(sizeof(int) * N); /* B 存中间序列 */
	for (i=0; i<N; i++) scanf("%d", &A[i]);
	for (i=0; i<N; i++) scanf("%d", &B[i]);
	if ( k = IsInsertion(A, B, N) ) /* 如果是插入排序 */ 
		NextInsertion(B, N, k); /* 执行下一步插入 */
	else
		NextMerge(B, N); /* 否则执行下一步归并 */

	return 0;
}

