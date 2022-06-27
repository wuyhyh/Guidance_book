#include <stdio.h>

#define MAXN 100000

int main()
{
	int A, N;
	int S[MAXN], K[MAXN], C, i, j;

	scanf("%d %d", &A, &N);
	if (!N) { /* ����NΪ0ʱ��������� */
		printf("0\n");
		return 0;
	}
	for (i=0; i<N; i++) {
        S[i] = 0; /* ��ʼ�������͸�λ��Ϊ0 */
        K[i] = A; /* �������ÿλ����A */
    }
	C = 0;  /* ��ʼ����λΪ0 */
	for (i=0; i<N; i++) {      /* ��ÿ��������K[0]~K[i]*/
		for (j=0; j<=i; j++) { /* ��λ��� */
			S[j] += (K[j]+C);
		    C = S[j]/10;
		    S[j] %= 10;
		}
	}
	if (C) printf("%d", C); /* ������λ�Ľ�λ */
	for (i=N-1; i>=0; i--)
		printf("%d", S[i]);
	printf("\n");

    return 0;
}

