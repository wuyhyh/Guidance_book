List Delete( List L, ElementType minD, ElementType maxD )
{
    int i, p;

    for (i=0; i<=L->Last; i++)
        if ((L->Data[i]>minD) && (L->Data[i]<maxD))
			break; /*�ҵ���1����ɾԪ��*/
    p = i; /* pָ������߿������Ŀո� */
    for (; i<=L->Last; i++) /* i��������ɨ�� */
        if (!((L->Data[i]>minD) && (L->Data[i]<maxD)))
			/* ��ÿ��Ӧ������Ԫ�� */
            L->Data[p++] = L->Data[i]; /* ��֮�浽����߿������Ŀո� */
             /* p���������ƶ�1��ָ����һ������߿������Ŀո� */
    L->Last = p-1; /* p���ָ���β���һ���ո� */
    
    return L; 
}

