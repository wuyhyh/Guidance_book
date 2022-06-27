void NonRec_DFS( LGraph Graph, Vertex V )
{ /* ͼGraph�ķǵݹ������������ */
	PtrToAdjVNode p;
    Stack S = CreateStack(); /* ��¼�����㼣���൱�ڷ���·�� */

	Visited[V] = true;	/* ��Ƿ��ʵ��Ľ��,�൱�ڵ�Ʋ��� */
	printf("%d", V+1);	/* �����ĵ� */
	Push(S, V);			/* ��¼����·�ߣ��൱�ڷ������� */
	while( !IsEmpty(S) )
	{
		V = Peek(S); /* ���ջ��Ԫ��V */
		/* ɨ��V�������ڽӵ� */
		for ( p=Graph->G[V].FirstEdge->Next; p; p=p->Next ) {
			if ( !Visited[p->AdjV] ) { /* �ҵ���һյû���� */
				Visited[p->AdjV] = true;
				printf(" %d", p->AdjV+1); /* ��� */
				Push(S, p->AdjV); /* ���� */
				break;
			}
		}
		if( !p ) /* �ڽӵ㶼�Ѿ������� */
		{	V = Pop(S);  /* �س�����·�ߣ��൱���������� */
			if( !IsEmpty(S) ) 
				printf(" %d", Peek(S)+1); /* ԭ·���� */
		}
	}
}

