void ToPostfix( char *expr )
{
	int i, j, L;
	char Postfix[2*MAXL], Op;
	Stack S;
	Precedence token;

	S = CreateStack( MAXL );
	L = strlen(expr);
	j = 0; /* jָ��Postfix[]�е�ǰҪд���λ�� */
	for (i=0; i<L; i++) {
		Op = GetOp(expr, &i, Postfix, &j);
		token = GetToken( Op );
		if (token == operand) continue; /* ���������� */
		switch(token) { /* ��������� */
			case lpr: Push(S, '('); break; /* ��������ջ */
			case rpr: /* �����ڵ���׺���ʽ�Ѿ�ɨ����� */
				/* ��������ǰ�����������д��Postfix[]*/
				while (Peek(S)!='(') {
					Postfix[j++] = Pop(S);
					Postfix[j++] = ' ';
				}
				Pop(S); /* ɾ�������� */
				break;
			default: /* ��������� */
				while (!IsEmpty(S) && Peek(S)!='(' && token <= GetToken(Peek(S))) {
					Postfix[j++] = Pop(S); 
					Postfix[j++] = ' ';
				}
				Push(S, Op);
				break;
		}
	}
	while (!IsEmpty(S)) {
		Postfix[j++] = Pop(S);
		Postfix[j++] = ' ';
	}
	Postfix[j-1] = '\0';
	printf("%s\n", Postfix);
}

