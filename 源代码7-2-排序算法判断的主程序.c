#include <stdio.h>
#include <stdlib.h>

int IsInsertion( int *A, int *B, int N ); /* �ж��Ƿ�������� */
void PrintResults( int *B, int N ); /* ���������� */
void NextInsertion( int *B, int N, int K ); /* ִ����һ������ */
int MergeLength( int *B, int N ); /* �ҳ��鲢�γ��� */
void NextMerge( int *B, int N ); /* ִ����һ���鲢 */

int main()
{
	int N, i, k;
	int *A, *B;

	scanf("%d", &N);
	A = (int *)malloc(sizeof(int) * N); /* A ��ԭʼ���� */
	B = (int *)malloc(sizeof(int) * N); /* B ���м����� */
	for (i=0; i<N; i++) scanf("%d", &A[i]);
	for (i=0; i<N; i++) scanf("%d", &B[i]);
	if ( k = IsInsertion(A, B, N) ) /* ����ǲ������� */ 
		NextInsertion(B, N, k); /* ִ����һ������ */
	else
		NextMerge(B, N); /* ����ִ����һ���鲢 */

	return 0;
}

