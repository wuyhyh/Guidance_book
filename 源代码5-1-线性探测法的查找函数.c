Position Find( HashTable H, ElementType Key )
{
	Position CurrentPos, NewPos;

    /* ��ɢ�е�ַ��ʼ */
	NewPos = CurrentPos = Hash( Key, H->TableSize );
    /* ����Ԫ���յ�����Keyʱ */
	while( H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key ) {
        NewPos ++; /* ����̽�� */
	    if ( NewPos >= H->TableSize ) /* ��β�۷�����ͷ */
			NewPos -= H->TableSize;
           /* ����ص������أ�˵�������� */
	    if (NewPos == CurrentPos) return ERROR;
	}
	return NewPos; /* ��ʱ���������յ�Ԫ�������ҵ�Key */
}

