bool IsSign( char *expr, int i)
{
	if ( !i || (!isdigit(expr[i-1]) && (expr[i-1]!=')')) )
		return true;
	else return false;

}

char GetOp( char *expr, int *i, char *Postfix, int *j )
{ /* �����������ֱ��д��Postfix[]������'0'��
     �����������򷵻��ַ� */
	
	if ( isdigit(expr[(*i)]) ) { /* ����һ�������� */ 
		while (isdigit(expr[(*i)]) || (expr[(*i)]=='.'))
			Postfix[(*j)++] = expr[(*i)++]; 
		Postfix[(*j)++] = ' ';
		(*i)--;
		return '0';
	}
	switch ( expr[(*i)] ) {
	case '+': 
		if ( IsSign(expr, (*i)) ) {/* ��������� */
			(*i)++;
			return GetOp(expr, i, Postfix, j);
		}
		else return '+';
	case '-':
		if ( IsSign(expr, (*i)) ) { /* ����Ǹ��� */
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
{ /* ������������ȼ����� */
	
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

