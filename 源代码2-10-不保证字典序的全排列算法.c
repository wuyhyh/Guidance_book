#include <stdio.h>

#define MAXN 9

void Swap( int L[], int i, int j )
{ /* ����L[i]��L[j] */
	int Tmp = L[i]; L[i] = L[j]; L[j] = Tmp;
}

void Permutation( int L[], int Left, int Right )
{ /* �ݹ鴦���L[Left]��L[Right]��ȫ���� */
    int i;

    if ( Left==Right ) { /* ���ֻʣ1�����֣��������ǰ��һ������ */
        for ( i=0; i<=Right; i++ ) printf("%d", L[i]);
        printf("\n");
    }
    else {
        for ( i=Left; i<=Right; i++) {
            Swap(L, Left, i); /* ������i�����֣������������ */
            Permutation( L, Left+1, Right ); /* �ݹ���ʣ������ */
            Swap(L, Left, i); /* ���һ�����к�ָ�ԭò */
        }
    }
}

int main()
{
    int N, L[MAXN], i;
    
    scanf("%d", &N);
    for (i=0; i<N; i++) L[i] = i+1; /* ��1~N˳��������� */
    Permutation(L, 0, N-1);
    
    return 0;
}

