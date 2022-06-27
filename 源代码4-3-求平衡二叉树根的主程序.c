#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
struct AVLNode{
	ElementType Data; /* 结点数据 */
	AVLTree Left;     /* 指向左子树 */
	AVLTree Right;    /* 指向右子树 */
	int H;            /* 树高 */
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
	AVLTree T = NULL; /* 初始为空的AVL树 */

	scanf("%d", &N);
	for ( i=0; i<N; i++ ) {
		scanf("%d", &K);
		T = Insert(T, K); /* 逐一插入 */
	}
	printf("%d\n", T->Data); /* 打印根结点 */

	return 0;
}

