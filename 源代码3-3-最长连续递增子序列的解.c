#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput()
{
	List L;
	int N;

	L = (List)malloc(sizeof(struct LNode));
	scanf("%d", &N);
	for ( L->Last=0; L->Last<N; L->Last++ )
		scanf("%d", &L->Data[L->Last]);
	L->Last--;
	return L;
}

void PrintResult( List L, Position Left, Position Right )
{
	Position i;
	
	printf("%d", L->Data[Left]);
	for ( i=Left+1; i<=Right; i++ )
		printf(" %d", L->Data[i]);
	printf("\n");
}

int main()
{
	List L;
	Position Left, Right, thisL, thisR, i;
	int maxLen, thisLen;
	
	L = ReadInput(); /* ������������ */
	/* ��ʼ����ǰ������ΪData[0] */
	Left = Right = thisL = thisR = 0;
	maxLen = thisLen = 1;
	
    for ( i=1; i<=L->Last; i++ ) {
        if ( L->Data[i]>L->Data[i-1] ) { /*����*/ 
           thisLen++; /* ��ǰ���ȵ���*/
           thisR++; /* ��ǰ�Ҷ˵����� */
        }
        else { /* Data[i]�����ڵ�ǰ������ */
            if ( thisLen > maxLen ) { /*�������� */ 
             	maxLen = thisLen;
             	Left = thisL; Right = thisR;
            }
             /* ��Data[i]������һ�������� */
            thisLen = 1; thisL = thisR = i;
        }
    }
    if ( thisLen > maxLen ) { /* ����ĩβ�������� */
       	maxLen = thisLen;
    	Left = thisL; Right = thisR;
    }
    PrintResult( L, Left, Right );
    
    return 0;
}

