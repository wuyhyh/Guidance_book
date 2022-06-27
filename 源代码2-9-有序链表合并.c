List Merge( List L1, List L2 )
{
    List L3, Rear;

    L3 = (PtrToNode)malloc(sizeof(struct Node)); /* ��ͷ��� */
	L3->Next = NULL;
    Rear = L3; /* βָ���ʼ״̬��ָ��ͷ��� */
    while (L1->Next && L2->Next) { /* ��L1��L2��û�����ʱ */
		if (L1->Next->Data < L2->Next->Data) { /* ���L1��С */
           /* ��L1��ǰ���ժ��������L3ĩβ */
           Rear->Next = L1->Next;
           L1->Next = L1->Next->Next;
           Rear->Next->Next = NULL;
           Rear = Rear->Next;
		}
		else {/* ���L2��С */
           /* ��L2��ǰ���ժ��������L3ĩβ */
           Rear->Next = L2->Next;
           L2->Next = L2->Next->Next;
           Rear->Next->Next = NULL;
           Rear = Rear->Next;
		}
	}
	if ( L1->Next ) { /* ��L1��ʣ������ת����L3��ĩβ*/
        Rear->Next = L1->Next;
        L1->Next = NULL;
	}
	if ( L2->Next ) { /* ��L2��ʣ������ת����L3��ĩβ*/
        Rear->Next = L2->Next;
        L2->Next = NULL;
	}
	return L3;
}

