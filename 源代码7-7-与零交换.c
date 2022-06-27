#include <stdio.h>

#define MAXN 100000

int main()
{
	int i, Tmp, Next, N, Cnt, flag;
	int A[MAXN], T[MAXN];
	
	scanf("%d", &N);
	for ( i=0; i<N; i++ ) {
		scanf("%d", &A[i]);
		T[A[i]] = i; /* ��ʼ���� */
	}
	Cnt = 0;
	for ( i=0; i<N; i++ ) {
		if ( T[i] == i ) continue; /* λ����ȷ���򲻴��� */
		flag = 0;
		Tmp = T[i]; /* ����i��Ԫ����ʱ��ţ��൱�ڰ�0�������� */
		T[i] = i; /* ��ʶ���Ľ��� */
		Cnt++; /* ��ʼ��1��Ԫ�� */
		if ( Tmp == 0 ) flag = 1; /* ���0�ڻ��У�����һ�� */
		while ( Tmp != T[Tmp] ) { /* ����û�н��� */
			/* ִ��һ����0���� */ 
			Next = T[Tmp]; 
			T[Tmp] = Tmp;
			Tmp = Next;
			if ( Tmp == 0 ) flag = 1; /* ���0�ڻ��У�����һ�� */
			Cnt++; /* ����1�� */
		}
		if ( flag ) Cnt--; /* ���0�ڻ��У���ΪԪ�ظ�����1 */
		else Cnt++; /* ����ΪԪ�ظ�����1 */
	}
	printf("%d\n", Cnt);

	return 0;
}

