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
{
	S->Data[++(S->Top)] = X;
}

ElementType Peek( Stack S )
{
	return ( S->Data[S->Top] );
}

void Pop( Stack S )
{
	(S->Top)--;
}

