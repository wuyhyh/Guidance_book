List Insert( List L, ElementType X )
{
    List Pre, Tmp;

    Pre = L; /* ǰ������ͷ��㿪ʼ */
    while ( Pre->Next ) { /* ��Pre����һ��������ʱ */
        if ( X < Pre->Next->Data) break; /* �ҵ���һ����X��Ľ�� */
        else Pre = Pre->Next;
    }
    Tmp = (PtrToNode)malloc(sizeof(struct Node));
    Tmp->Data = X;  /* ����X��� */
    Tmp->Next = Pre->Next;
    Pre->Next = Tmp; /* ��X����Pre��һ��λ�� */

    return L;
}

