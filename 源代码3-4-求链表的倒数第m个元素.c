ElementType Find( List L, int m )
{
	List p1, p2;
	int Counter;
	
	p1 = p2 = L;
	Counter = 0;
	while ( p1 && (++Counter <= m))
		p1 = p1->Next;  /* p1�ƶ�����m����� */
	if (Counter <= m)
		return ERROR; /* m�����������ȣ������ڵ�����m��Ԫ�� */
	while ( p1 ) { /* ��ָ��ͬ���ƶ���ֱ��p1�����β */
		p1 = p1->Next;
		p2 = p2->Next;
	}
	return p2->Data; /* ��ʱp2ָ������m��Ԫ�� */
}

