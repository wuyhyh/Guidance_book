#include <stdio.h>

int main()
{
    int A, N, K, S, i;

    scanf("%d %d", &A, &N);
    if (!N) { /* ����NΪ0ʱ��������� */
	    printf("0\n");
		return 0;
	}
    S = K = A; /* ��ʼ��K���ܺ�S */
    for (i=1; i<N; i++) {
        K = K*10 + A; /* ������һ�������� */
        S += K;
    }
    printf("%d\n", S);

    return 0;
}

