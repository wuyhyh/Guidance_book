#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXL 21
typedef enum{ false, true } bool;
typedef char ElementType;

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
ElementType Pop( Stack S );
/*-----堆栈的定义结束 -----*/ 

typedef enum {lpr, rpr, plus, minus, times, divide, eos, operand}
        Precedence; /* 运算符的优先级类型 */

bool IsSign( char *expr, int i);
char GetOp( char *expr, int *i, char *Postfix, int *j );
Precedence GetToken( char op );
void ToPostfix( char *Expr );

int main()
{
	char Str[MAXL];

	scanf("%s", Str);
	ToPostfix( Str );
	return 0;
}

