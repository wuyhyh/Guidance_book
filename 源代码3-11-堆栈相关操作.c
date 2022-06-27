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

bool IsFull( Stack S )
{
	return (S->Top == (S->MaxSize-1));
}

bool Push( Stack S, ElementType X )
{
	if ( IsFull(S) ) return false;
	else  {
		S->Data[++(S->Top)] = X;
		return true;
	}
}

bool Pop( Stack S )
{
	if ( IsEmpty(S) ) return false;
	else {
		(S->Top)--;
		return true;
	}
}

void Clear( Stack S )
{
	while ( !IsEmpty(S) ) Pop(S);
}

