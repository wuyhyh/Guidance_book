void InitializeVSet( SetType S, int N )
{ /* 初始化并查集 */
	ElementType X;
	for ( X=0; X<N; X++ ) S[X] = -1;
}

void Union( SetType S, SetName Root1, SetName Root2 )
{ /* 这里默认Root1和Root2是不同集合的根结点 */
	/* 保证小集合并入大集合 */
	if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
		S[Root2] += S[Root1];	 /* 集合1并入集合2  */
		S[Root1] = Root2;
	}
	else {						 /* 如果集合1比较大 */
		S[Root1] += S[Root2];	 /* 集合2并入集合1  */
		S[Root2] = Root1;
	}
}

SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
	if ( S[X] < 0 ) /* 找到集合的根 */
		return X;
	else
		return S[X] = Find( S, S[X] ); /* 路径压缩 */
}

