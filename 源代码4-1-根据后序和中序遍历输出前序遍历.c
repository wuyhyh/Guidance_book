#include <stdio.h>
#include <stdlib.h>

#define MAXN 30
typedef int ElementType;

typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
	ElementType Data; /* ������� */
	BinTree Left;     /* ָ�������� */
	BinTree Right;    /* ָ�������� */
};

BinTree BuildTree( int Inorder[], int Postorder[], int N );
void PreorderTraversal( BinTree BT );

int main()
{
    BinTree T;
    int Inorder[MAXN], Postorder[MAXN], N, i;

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &Postorder[i]);
    for (i=0; i<N; i++) scanf("%d", &Inorder[i]);
    T = BuildTree(Inorder, Postorder, N);
    printf("Preorder:"); PreorderTraversal(T); printf("\n");

    return 0;
}

BinTree BuildTree( int Inorder[], int Postorder[], int N )
{ /* ��������ͺ��������е�N����㽨�� */
     BinTree T;
     int p;
     
     if (!N) return NULL; /* �ݹ���ֹ���������� */
     
     T = (BinTree)malloc(sizeof(struct TNode));
     T->Data = Postorder[N-1]; /* ������Ǻ������һ�� */
     T->Left = T->Right = NULL;
     
     for (p=0; p<N; p++) /* ���������Ҹ���� */
         if (Inorder[p]==Postorder[N-1]) break;
         
     T->Left = BuildTree( Inorder, Postorder, p );
     T->Right = BuildTree( Inorder+p+1, Postorder+p, N-p-1 );
     
     return T;
}
 
void PreorderTraversal( BinTree T )
{
    if( T ) {
        printf(" %d", T->Data );
        PreorderTraversal( T->Left );
        PreorderTraversal( T->Right );
    }
}

