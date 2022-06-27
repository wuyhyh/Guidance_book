#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE  100
typedef enum{ false, true } bool;

typedef struct {
	int   N; /* ����  */
	char  A; /* ��ʼ��  */
	char  B; /* ������  */
	char  C; /* Ŀ����  */
} ElementType;  /* ��ŵ������ṹ���� */

/*-----��ջ�Ķ��� -----*/ 
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType *Data;
	Position Top;
	int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack( int MaxSize );
bool IsEmpty( Stack S );
void Push( Stack S, ElementType X );
ElementType Pop( Stack S );
/*-----��ջ�Ķ������ -----*/ 

void Hanoi( int n )    /* ������ջ�ķǵݹ�ʵ�� */
{
    Stack S;
	ElementType P, toPush;
	
	/* ��ʼ�� */
	S = CreateStack( MAXSIZE );
	P.N = n;  P.A='a';  P.B='b';  P.C='c';
	Push(S, P); /* ����ʼ����(n,a,b,c)�����ջ */
	while ( !IsEmpty(S) ) { /* ����ջ����ʱ */
        P = Pop(S);
        if ( P.N == 1)
			printf("%c -> %c\n", P.A, P.C);
        else {
			toPush.N = P.N - 1;
			toPush.A = P.B; toPush.B = P.A; toPush.C = P.C;
			Push( S, toPush ); /* ���ڶ�������������(n-1,b,a,c)��ջ */
			toPush.N = 1;
			toPush.A = P.A; toPush.B = P.B; toPush.C = P.C;
			Push( S, toPush ); /* ����ֱ������������(1,a,b,c)��ջ */
			toPush.N = P.N - 1;
			toPush.A = P.A; toPush.B = P.C; toPush.C = P.B;
			Push( S, toPush ); /* ����һ������������(n-1,a,c,b)��ջ */
        }
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	Hanoi(n);
	return 0;
}

