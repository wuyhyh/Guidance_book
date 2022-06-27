bool IsEnd( int newline, char *c )
{ /* �ж��Ƿ������β */
	if ( newline && (*c)=='.' ) {
		scanf("%c", c);
		if ((*c)=='\n') return true;
		else return false;
	}
	else return false;
}

Token GetToken( char c )
{ /* �����ַ������� */
	switch(c) {
       case '\n': return ret;
       case '{': return lbrc;
       case '[': return lbrkt;
       case '(': return lpr;
       case '/': 
            scanf("%c", &c);
            if (c=='*') return lc;
            else return GetToken(c);
            /* ���������ע�ͷ�����Ҫ���c������ */
       case '}': return rbrc;
       case ']': return rbrkt;
       case ')': return rpr;
       case '*':
            scanf("%c", &c);
            if (c=='/') return rc;
            else return GetToken(c);
            /* ���������ע�ͷ�����Ҫ���c������ */
       default: return others;
    }
}

bool IsPaired(Token t1, Token t2)
{
	return (t1-t2)==4;
	/* t1���Ұ����t2������ */
	/* ������ǵ�enumֵ��4��˵����ƥ��� */
}

void PrintS( Token t )
{
	switch(t) {
		case lc: printf("/*"); break;
		case lbrc: printf("{"); break;
		case lbrkt: printf("["); break;
		case lpr: printf("("); break;
		case rc: printf("*/"); break;
		case rbrc: printf("}"); break;
		case rbrkt: printf("]"); break;
		case rpr: printf(")"); break;
		default: break;
	}
}

