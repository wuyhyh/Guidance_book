#include <stdio.h>

int main()
{
	int Sum, X;
	char Op;
	scanf("%d%c", &Sum, &Op);	
	/* �����һ���������Լ������������������޿ո񣬹������ر��� */
	while(Op != '=') {
		scanf("%d", &X);		/* ������һ�������� */
		switch(Op) {
			case '+':			/* ���ݲ�����������Ӧ���� */
				Sum += X;
				break;
			case '-':
				Sum -= X;
				break;
			case '*':
				Sum *= X;
				break;
			case '/':
                if ( X==0 ) {
                    printf("ERROR\n");
					return 0;
				}
				Sum /= X;
				break;
			default:
				printf("ERROR\n");
				return 0;
		}
		scanf("%c", &Op);		/* ������һ�������� */
	}
	printf("%d\n", Sum);		/* ��ӡ��� */
	return 0;
}

