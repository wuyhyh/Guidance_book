Position BS( List L, ElementType X, Position Left, Position Right )
{ /* Left��Right�ֱ��ǵ�ǰҪ�����L->Data[]����������ҵ��±�ֵ */

	if (Left > Right) /* �����ǰ��Χ��û��Ԫ���� */
		return NotFound; /* ���ز��Ҳ��ɹ��ı�ʶ */

    Mid = (Left + Right) / 2; /* �����м�Ԫ������ */
	if ( L->Data[Mid] > X )
    	return BS( L, X, Left, Mid-1 ); /*����ߵ���ϵ���в���*/
	else if ( L->Data[Mid] < X )
    	return BS( L, X, Mid+1, Right ); /*���ұߵ���ϵ���в���*/
	else /* L->Data[Mid] == X */
    	return Mid; /* ���ҳɹ�����������Ԫ�ص��±� */
}

Position BinarySearch( List L, ElementType X )
{ /* ��˳��洢�ı�L�в��ҹؼ���ΪX������Ԫ�� */
	
	return BS( L, X, 1, L->Last );

}

