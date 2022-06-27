Queue CreateQueue( int MaxSize )
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool IsEmptyQ( Queue Q )
{
	return (Q->Front == Q->Rear);
}

void AddQ( Queue Q, ElementType X )
{ /* 简版入列，不检查队列满的问题 */
	Q->Rear = (Q->Rear+1)%Q->MaxSize;
	Q->Data[Q->Rear] = X;
}

ElementType DeleteQ( Queue Q )
{ /* 简版出列。不检查队列空的问题 */
	Q->Front =(Q->Front+1)%Q->MaxSize;
	return  Q->Data[Q->Front];
}

