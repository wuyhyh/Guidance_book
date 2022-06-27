#include <stdio.h>
#include <stdlib.h>

#define MAXS 101
#define MAXN 50

typedef enum{ false, true } bool;
typedef int ElementType;

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
bool IsFull( Stack S );
bool Push( Stack S, ElementType X );
bool Pop( Stack S );
void Clear( Stack S );
/*-----��ջ�Ķ������ -----*/ 

int main()
{
    int N, M, i, j;
    char Str[MAXS];
    Stack S;
    
    scanf("%d %d\n", &N, &M);
    S = CreateStack(M);
    
    for (i=0; i<N; i++) {
        scanf("%s", Str);
        Clear(S);
        for ( j=0; Str[j]!='\0'; j++ ) {
           if ((Str[j]=='S') && (!Push(S, 1))) break;
           if ((Str[j]=='X') && (!Pop(S))) break;
        }
        if ((Str[j]=='\0') && IsEmpty(S)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

