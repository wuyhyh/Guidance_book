bool IsEnd( int newline, char *c )
{ /* 判断是否读到结尾 */
	if ( newline && (*c)=='.' ) {
		scanf("%c", c);
		if ((*c)=='\n') return true;
		else return false;
	}
	else return false;
}

Token GetToken( char c )
{ /* 返回字符的类型 */
	switch(c) {
       case '\n': return ret;
       case '{': return lbrc;
       case '[': return lbrkt;
       case '(': return lpr;
       case '/': 
            scanf("%c", &c);
            if (c=='*') return lc;
            else return GetToken(c);
            /* 如果不是左注释符，还要检查c的类型 */
       case '}': return rbrc;
       case ']': return rbrkt;
       case ')': return rpr;
       case '*':
            scanf("%c", &c);
            if (c=='/') return rc;
            else return GetToken(c);
            /* 如果不是右注释符，还要检查c的类型 */
       default: return others;
    }
}

bool IsPaired(Token t1, Token t2)
{
	return (t1-t2)==4;
	/* t1是右半符，t2是左半符 */
	/* 如果它们的enum值差4，说明是匹配的 */
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

