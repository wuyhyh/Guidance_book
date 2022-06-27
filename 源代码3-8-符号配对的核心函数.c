int Check( Token *T1, Token *T2 )
{
	Stack S; /* ���ƥ���õĶ�ջ */
	char c;  /* �������ַ� */
	Token t; /* ���ַ�ת��������� */
	int newline, error; /* newline��ʶ��ǰ�Ƿ����У�error��ʶ���� */
	
	S = CreateStack(MAXN);
	newline = 1; error = 0; /* ��ʼΪ���У�û�д��� */
	while(1) {
		scanf("%c", &c);
		if (IsEnd(newline, &c)) break; /* ����Ѿ�������β��������ѭ�� */
		else {
			switch(t = GetToken(c)) { /* ����c������ */
				/* ��������� */
				case lc:
				case lbrc:
				case lbrkt:
				case lpr: 
					/* ������ջ������������ */
					Push(S, t); newline = 0; break;
				/* ������Ұ�� */
				case rc:
				case rbrc:
				case rbrkt:
				case rpr: 
					/* ����ջ�ѿգ��Ұ����ƥ�� */
					if (IsEmpty(S)) error = 1;
					/* ��ջ��Ԫ�غ͵�ǰ���벻ƥ�䣬������ƥ��*/
					else if (!IsPaired(t, Peek(S))) error = 2;
					else Pop(S); /* һ����������ȥһ�� */
					newline = 0; /* ���������� */
					break;
				case ret: newline = 1; break; /* ���س����ʶ���� */ 
				default: newline = 0; break; /* �����ַ����������� */
			}
			if (error) break; /* ������ִ���������ѭ�� */
		}
	}
	/* ������βʱ��ջ��û�գ������ж� */ 
	if (!error && !IsEmpty(S)) error = 2;
	(*T1) = t; (*T2) = Peek(S);
	
	return error;
}

