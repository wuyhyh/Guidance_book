void InitializeVSet( SetType S, int N )
{ /* ��ʼ�����鼯 */
	ElementType X;
	for ( X=0; X<N; X++ ) S[X] = -1;
}

void Union( SetType S, SetName Root1, SetName Root2 )
{ /* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
	/* ��֤С���ϲ���󼯺� */
	if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
		S[Root2] += S[Root1];	 /* ����1���뼯��2  */
		S[Root1] = Root2;
	}
	else {						 /* �������1�Ƚϴ� */
		S[Root1] += S[Root2];	 /* ����2���뼯��1  */
		S[Root2] = Root1;
	}
}

SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
	if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
		return X;
	else
		return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
}

