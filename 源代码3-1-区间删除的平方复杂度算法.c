List Delete( List L, ElementType minD, ElementType maxD )
{
    int i, j;

    for ( i=0; i<=L->Last; i++ ) /* ɨ��ÿ��Ԫ��L->Data[i] */
        if ((L->Data[i]>minD) && (L->Data[i]<maxD)) { /* ���Ҫɾ�� */
           	for ( j=i+1; j<=L->Last; j++ )
				L->Data[j-1] = L->Data[j]; /* �������� */
           	L->Last--; /* /* ���±�L->Last */
			i--; /* ��iָ��ǰ���һ����ɾ����Ԫ��*/
        }
           
    return L;
}

