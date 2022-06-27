#include <stdio.h>
#include <stdlib.h>

#define MAXN 100
typedef enum{ false, true } bool;
typedef enum{ ret, lc, lbrc, lbrkt, lpr, rc, rbrc, rbrkt, rpr, others } Token;
typedef Token ElementType;

/*-----堆栈的定义 -----*/ 
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
ElementType Peek( Stack S );
void Pop( Stack S );
/*-----堆栈的定义结束 -----*/ 

bool IsEnd( int newline, char *c );
Token GetToken( char c );
bool IsPaired(Token t1, Token t2);
void PrintS( Token t );
int Check( Token *T1, Token *T2 );

int main()
{
	Token T1, T2;
	int error = Check(&T1, &T2);
	
	if (!error) printf("YES\n");
	else {
		printf("NO\n");
		switch(error) {
			case 1: printf("?-"); PrintS(T1); break;
			case 2: PrintS(T2); printf("-?"); break;
			default: break;
		}
		printf("\n");
	}
	return 0;
}

