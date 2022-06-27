bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 )
{ /* �������V1��V2�ı��Ƿ������е���С�������Ӽ��й��ɻ�· */
	Vertex Root1, Root2;

	Root1 = Find( VSet, V1 ); /* �õ�V1��������ͨ������ */
	Root2 = Find( VSet, V2 ); /* �õ�V2��������ͨ������ */

	if( Root1==Root2 ) /* ��V1��V2�Ѿ���ͨ����ñ߲���Ҫ */
		return false;
	else { /* ����ñ߿��Ա��ռ���ͬʱ��V1��V2����ͬһ��ͨ�� */
		Union( VSet, Root1, Root2 );
		return true;
	}
}

int Kruskal( LGraph Graph )
{ /* ������С������Ȩ�غ� */
	WeightType TotalWeight;
    int ECount, NextEdge;
	SetType VSet; /* �������� */
	Edge ESet;    /* ������ */

	InitializeVSet( VSet, Graph->Nv ); /* ��ʼ�����㲢�鼯 */
	ESet = (Edge)malloc( sizeof(struct ENode)*Graph->Ne );
	InitializeESet( Graph, ESet ); /* ��ʼ���ߵ���С�� */
    TotalWeight = 0; /* ��ʼ��Ȩ�غ�     */
    ECount = 0;      /* ��ʼ����¼�ı��� */

	NextEdge = Graph->Ne; /* ԭʼ�߼��Ĺ�ģ */
	while ( ECount < Graph->Nv-1 ) {  /* ���ռ��ı߲����Թ�����ʱ */
        /* �ӱ߼��еõ���С�ߵ�λ�� */
		NextEdge = GetEdge( ESet, NextEdge ); 
		if (NextEdge < 0) /* �߼��ѿ� */
			break;
        /* ����ñߵļ��벻���ɻ�·�������˽�㲻����ͬһ��ͨ�� */
		if ( CheckCycle( VSet, ESet[NextEdge].V1, ESet[NextEdge].V2 ) == true ) {
			TotalWeight += ESet[NextEdge].Weight; /* �ۼ�Ȩ�� */
			ECount++; /* �������б�����1 */
		}
	}
	if ( ECount < Graph->Nv-1 )
		TotalWeight = -1; /* ���ô����ǣ���ʾ������������ */

	return TotalWeight;
}

