int Check( Token *T1, Token *T2 )
{
	Stack S; /* 检测匹配用的堆栈 */
	char c;  /* 存读入的字符 */
	Token t; /* 存字符转换后的类型 */
	int newline, error; /* newline标识当前是否新行，error标识错误 */
	
	S = CreateStack(MAXN);
	newline = 1; error = 0; /* 初始为新行，没有错误 */
	while(1) {
		scanf("%c", &c);
		if (IsEnd(newline, &c)) break; /* 如果已经读到结尾，则跳出循环 */
		else {
			switch(t = GetToken(c)) { /* 解析c的类型 */
				/* 如果是左半符 */
				case lc:
				case lbrc:
				case lbrkt:
				case lpr: 
					/* 左半符入栈，不再是新行 */
					Push(S, t); newline = 0; break;
				/* 如果是右半符 */
				case rc:
				case rbrc:
				case rbrkt:
				case rpr: 
					/* 若堆栈已空，右半符不匹配 */
					if (IsEmpty(S)) error = 1;
					/* 若栈顶元素和当前读入不匹配，左半符不匹配*/
					else if (!IsPaired(t, Peek(S))) error = 2;
					else Pop(S); /* 一切正常，消去一对 */
					newline = 0; /* 不再是新行 */
					break;
				case ret: newline = 1; break; /* 遇回车则标识新行 */ 
				default: newline = 0; break; /* 其他字符跳过不处理 */
			}
			if (error) break; /* 如果发现错误则跳出循环 */
		}
	}
	/* 读到结尾时堆栈还没空，左半符有多 */ 
	if (!error && !IsEmpty(S)) error = 2;
	(*T1) = t; (*T2) = Peek(S);
	
	return error;
}

