bool IsSign( char *expr, int i)
{
	if ( !i || (!isdigit(expr[i-1]) && (expr[i-1]!=')')) )
		return true;
	else return false;

}

char GetOp( char *expr, int *i, char *Postfix, int *j )
{ /* 如果是数字则直接写入Postfix[]并返回'0'；
     如果是运算符则返回字符 */
	
	if ( isdigit(expr[(*i)]) ) { /* 读入一个纯数字 */ 
		while (isdigit(expr[(*i)]) || (expr[(*i)]=='.'))
			Postfix[(*j)++] = expr[(*i)++]; 
		Postfix[(*j)++] = ' ';
		(*i)--;
		return '0';
	}
	switch ( expr[(*i)] ) {
	case '+': 
		if ( IsSign(expr, (*i)) ) {/* 如果是正号 */
			(*i)++;
			return GetOp(expr, i, Postfix, j);
		}
		else return '+';
	case '-':
		if ( IsSign(expr, (*i)) ) { /* 如果是负号 */
			Postfix[(*j)++] = '-'; 
			(*i)++;
			return GetOp(expr, i, Postfix, j);
		}
		else return '-';
	default:
		return  expr[(*i)]; 
	}
}

Precedence GetToken( char op )
{ /* 返回运算符优先级类型 */
	
	switch ( op ) {
		case '(':	return lpr;
		case ')':	return rpr;
		case '+':	return plus;
		case '-':	return minus;
		case '*':  return times;
		case '/':  return divide;
		case '\0':  return eos;
		default:	return operand; 
	}
}

