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
{ /* ������У����������������� */
	Q->Rear = (Q->Rear+1)%Q->MaxSize;
	Q->Data[Q->Rear] = X;
}

ElementType DeleteQ( Queue Q )
{ /* �����С��������пյ����� */
	Q->Front =(Q->Front+1)%Q->MaxSize;
	return  Q->Data[Q->Front];
}

