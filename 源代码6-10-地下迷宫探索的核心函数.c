void NonRec_DFS( LGraph Graph, Vertex V )
{ /* 图Graph的非递归深度优先搜索 */
	PtrToAdjVNode p;
    Stack S = CreateStack(); /* 记录访问足迹，相当于放绳路径 */

	Visited[V] = true;	/* 标记访问到的结点,相当于点灯操作 */
	printf("%d", V+1);	/* 点起点的灯 */
	Push(S, V);			/* 记录访问路线，相当于放绳操作 */
	while( !IsEmpty(S) )
	{
		V = Peek(S); /* 检查栈顶元素V */
		/* 扫描V的所有邻接点 */
		for ( p=Graph->G[V].FirstEdge->Next; p; p=p->Next ) {
			if ( !Visited[p->AdjV] ) { /* 找到第一盏没亮的 */
				Visited[p->AdjV] = true;
				printf(" %d", p->AdjV+1); /* 点灯 */
				Push(S, p->AdjV); /* 放绳 */
				break;
			}
		}
		if( !p ) /* 邻接点都已经点亮了 */
		{	V = Pop(S);  /* 回撤访问路线，相当于收绳操作 */
			if( !IsEmpty(S) ) 
				printf(" %d", Peek(S)+1); /* 原路返回 */
		}
	}
}

