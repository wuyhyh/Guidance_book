int GetH( AVLTree T )
{ /* ����T�ĸ߶� */
	if ( T ) return T->H;
	else return -1;
}

AVLTree LL( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B */
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->H = Max( GetH(A->Left), GetH(A->Right) ) + 1;
	B->H = Max( GetH(B->Left), A->H ) + 1;
	return B;
}

AVLTree RR ( AVLTree A )
{ /* ע�⣺A������һ�����ӽ��B */
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->H = Max( GetH(A->Left), GetH(A->Right) ) + 1;
	B->H = Max( GetH(B->Left), A->H ) + 1;
	return B;
}

AVLTree LR( AVLTree A )
{ /* LR˫����ֱ��ʵ�� */
	AVLTree B, C;
	B = A->Left;
	C = B->Right;
	B->Right = C->Left;
	A->Left = C->Right;
	C->Left = B;
	C->Right = A;
	B->H = Max(GetH(B->Left), GetH(B->Right)) + 1;
	A->H = Max(GetH(A->Left), GetH(A->Right)) + 1;
	C->H = Max(B->H, A->H) + 1;
	return C;
}

AVLTree RL( AVLTree A )
{ /* RL˫����ֱ��ʵ�� */
	AVLTree B, C;
	B = A->Right;
	C = B->Left;
	B->Left = C->Right;
	A->Right = C->Left;
	C->Right = B;
	C->Left = A;
	B->H = Max(GetH(B->Left), GetH(B->Right)) + 1;
	A->H = Max(GetH(A->Left), GetH(A->Right)) + 1;
	C->H = Max(B->H, A->H) + 1;
	return C;
}

AVLTree Insert( AVLTree T, ElementType X )
{ /* ��X����AVL��T�У����ҷ��ص������AVL�� */
	if ( !T ) { /* ��������������½�����һ�������� */
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->H = 0;
		T->Left = T->Right = NULL;
	} /* if (�������) ���� */

	else if ( X < T->Data ) {
		/* ����T�������� */
		T->Left = Insert( T->Left, X);
		/* �����Ҫ���� */
        if ( GetH(T->Left)-GetH(T->Right) == 2 )
            if ( X < T->Left->Data ) 
               T = LL(T);      /* ���� */
            else 
               T = LR(T); /* ��-��˫�� */
	} /* else if (����������) ���� */
    
	else if ( X > T->Data ) {
		/* ����T�������� */
		T->Right = Insert( T->Right, X );
		/* �����Ҫ���� */
        if ( GetH(T->Left)-GetH(T->Right) == -2 )
            if ( X > T->Right->Data ) 
               T = RR(T);     /* �ҵ��� */
            else 
               T = RL(T); /* ��-��˫�� */
	} /* else if (����������) ���� */
	/* else X == T->Data��������� */
	/* �����˸������� */
	T->H = Max( GetH(T->Left), GetH(T->Right) ) + 1;
	
	return T;
}

