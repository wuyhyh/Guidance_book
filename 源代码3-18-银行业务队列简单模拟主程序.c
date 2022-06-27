#include <stdio.h>
#include <stdlib.h>

#define MaxQSize  1000
typedef enum { false, true } bool;
typedef int ElementType;

/*-----���еĶ���-----*/
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue( int MaxSize );
bool IsEmptyQ( Queue Q );
void AddQ( Queue Q, ElementType X );
ElementType DeleteQ( Queue Q );
/*-----���еĶ������-----*/

int main()
{
	int N, Customer, i;
	Queue A, B;

	/* ��ʼ���������� */
	A = CreateQueue(MaxQSize);
	B = CreateQueue(MaxQSize);

	scanf("%d", &N);
	for(i=0; i<N; i++) {/* ������������ż�ԣ���ÿ������������Ӧ������ */
		scanf("%d", &Customer);
		if (Customer%2) AddQ(A, Customer);
		else AddQ(B, Customer);
	}
	/* �����1���˿� */
	if (!IsEmptyQ(A)) printf("%d", DeleteQ(A));
	else printf("%d", DeleteQ(B));
	/* �������Ĺ˿� */
	while (!IsEmptyQ(A) && !IsEmptyQ(B)) {  /*A��B�������ж����� */
        printf(" %d", DeleteQ(A));
	    printf(" %d", DeleteQ(B));
	    if (!IsEmptyQ(A)) printf(" %d", DeleteQ(A));
	}
	while (!IsEmptyQ(A))          /*A���в���,B�� */
        printf(" %d", DeleteQ(A));
	while (!IsEmptyQ(B))          /*B���в���,A�� */
        printf(" %d", DeleteQ(B));
	printf("\n");
    return 0;
}

