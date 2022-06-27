Position BinarySearch( List L, ElementType X )
{ /* ��˳��洢�ı�L�в��ҹؼ���ΪX������Ԫ�� */
	Position Left, Right, Mid;

    Left = 1;            /* ��ʼ��߽��±�ֵ */
    Right = L->Last; /* ��ʼ�ұ߽��±�ֵ */
    while( Left <= Right )
    {
        Mid = (Left + Right) / 2;  /* �����м�Ԫ������ */
        if( L->Data[Mid] > X )
			Right = Mid - 1; /* �����ұ߽� */
        else if( L->Data[Mid] < X )
			Left = Mid + 1;  /* ������߽� */
        else /* L->Data[Mid] == X */
			return Mid;   /* ���ҳɹ�����������Ԫ�ص��±� */
    }
    return NotFound;   /* ���ز��Ҳ��ɹ��ı�ʶ */
}

