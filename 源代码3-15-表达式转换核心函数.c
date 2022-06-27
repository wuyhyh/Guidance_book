void ToPostfix( char *expr )
{
	int i, j, L;
	char Postfix[2*MAXL], Op;
	Stack S;
	Precedence token;

	S = CreateStack( MAXL );
	L = strlen(expr);
	j = 0; /* j指向Postfix[]中当前要写入的位置 */
	for (i=0; i<L; i++) {
		Op = GetOp(expr, &i, Postfix, &j);
		token = GetToken( Op );
		if (token == operand) continue; /* 不处理数字 */
		switch(token) { /* 处理运算符 */
			case lpr: Push(S, '('); break; /* 左括号入栈 */
			case rpr: /* 括号内的中缀表达式已经扫描完毕 */
				/* 把左括号前的所有运算符写入Postfix[]*/
				while (Peek(S)!='(') {
					Postfix[j++] = Pop(S);
					Postfix[j++] = ' ';
				}
				Pop(S); /* 删除左括号 */
				break;
			default: /* 其它运算符 */
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

