#define ERROR -1
Vertex FindMinDist( MGraph Graph, int dist[], int collected[] )
{ /* ����δ����¼������dist��С�� */
	Vertex MinV, V;
	int MinDist = INFINITY;
	for (V=0; V<Graph->Nv; V++) {
		if ( collected[V]==false && dist[V]<MinDist) {
			/* ��Vδ����¼����dist[V]��С */
			MinDist = dist[V]; /* ������С���� */
			MinV = V; /* ���¶�Ӧ���� */
		}
	}
	if (MinDist < INFINITY) /* ���ҵ���Сdist */
		return MinV; /* ���ض�Ӧ�Ķ����±� */
	else return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
}

void Dijkstra( MGraph Graph, int dist[], int cost[], Vertex S )
{
	int collected[MaxVertexNum];
	Vertex V, W;

	/* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
	for ( V=0; V<Graph->Nv; V++ ) {
        dist[V] = Graph->Dist[S][V];
        cost[V] = Graph->Cost[S][V];
        collected[V] = false;
    }
	dist[S] = cost[S] = 0;
	collected[S] = true; /* �Ƚ�������뼯�� */
	while (1) {
        /* V = δ����¼������dist��С�� */
		V = FindMinDist( Graph, dist, collected );
		if ( V==ERROR ) /* ��������V������ */
			break;      /* �㷨���� */
		collected[V] = true;  /* ��¼V */
		for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
		    /* ��W��V���ڽӵ㲢��δ����¼ */
		    if (collected[W]==false && Graph->Dist[V][W]<INFINITY){
				/* ����¼Vʹ��dist[W]��С */
				if ( dist[V]+Graph->Dist[V][W] < dist[W] ) {
                    /* ����dist[W] */
					dist[W] = dist[V]+Graph->Dist[V][W];
                    /* ����cost[W] */
					cost[W] = cost[V]+Graph->Cost[V][W];				}
				/* ���ߵȳ����Ǹ����� */
				else if ( dist[V]+Graph->Dist[V][W] == dist[W] &&
				          cost[V]+Graph->Cost[V][W] < cost[W] ) {
                    /* ����cost[W] */
					cost[W] = cost[V]+Graph->Cost[V][W];
				}
			}
	} /* while����*/
}

