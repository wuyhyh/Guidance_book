#include <stdio.h>

#define MAXN 100000

int main()
{
	int A, N;
	int i, S[MAXN], C;

	scanf("%d %d", &A, &N);
	if (!N) { /* ����NΪ0ʱ��������� */
		printf("0\n");
		return 0;
	}
	for (i=0; i<N; i++) S[i] = 0; /* ��ʼ�������͸�λ��Ϊ0 */
	C = 0;  /* ��ʼ����λΪ0 */
	for (i=0; i<N; i++) { /* ��ÿһλ */
		C += A * (N-i); /* ֱ�Ӽ����ۼӽ�� */
		S[i] = C%10;
		C /= 10;
	}
	if (C) printf("%d", C); /* ������λ�Ľ�λ */
	for (i=N-1; i>=0; i--)
		printf("%d", S[i]);
	printf("\n");

    return 0;
}

