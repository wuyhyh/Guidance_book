#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL������ */
struct AVLNode{
	ElementType Data; /* ������� */
	AVLTree Left;     /* ָ�������� */
	AVLTree Right;    /* ָ�������� */
	int H;            /* ���� */
};

int Max( int a, int b )
{
	return a > b ? a : b;
}

int GetH( AVLTree T );
AVLTree LL( AVLTree A );
AVLTree RR( AVLTree A );
AVLTree LR( AVLTree A );
AVLTree RL( AVLTree A );
AVLTree Insert( AVLTree T, ElementType X );

int main()
{
	int N, K, i;
	AVLTree T = NULL; /* ��ʼΪ�յ�AVL�� */

	scanf("%d", &N);
	for ( i=0; i<N; i++ ) {
		scanf("%d", &K);
		T = Insert(T, K); /* ��һ���� */
	}
	printf("%d\n", T->Data); /* ��ӡ����� */

	return 0;
}

