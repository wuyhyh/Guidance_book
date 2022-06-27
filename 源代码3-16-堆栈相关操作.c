Stack CreateStack( int MaxSize )
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsEmpty( Stack S )
{
	return (S->Top == -1);
}

void Push( Stack S, ElementType X )
{ /* 简版入栈，不担心栈满的问题 */
	S->Data[++(S->Top)] = X;
}

ElementType Peek( Stack S )
{
	return ( S->Data[S->Top] );
}

ElementType Pop( Stack S )
{ /* 简版出栈，不担心栈空的问题 */
	return ( S->Data[(S->Top)--] );
}

