#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode *PtrToPolyNode;
struct PolyNode {
	int Coef;
	int Expon;
	PtrToPolyNode Next;
};
typedef PtrToPolyNode Polynomial;

void Attach( int coef, int expon, Polynomial *PtrRear )
{   /* 将由(coef, expon)构成的新项插入到PtrRear间接指向的结点后面 */
	Polynomial P;

	P = (Polynomial)malloc(sizeof(struct PolyNode));  /* 申请一新结点 */
	P->Coef = coef;    /* 对新结点赋值  */
	P->Expon = expon;
	P->Next = NULL;
	(*PtrRear)->Next = P; /* 将P指向的新项插入到当前结果表达式尾项的后面 */
	*PtrRear = P;         /* 修改PtrRear值 */
}

Polynomial ReadPoly()
{   /* 读入并建立多项式 */
	Polynomial  P, Rear, t;
	int coef, expon, N;

	scanf("%d", &N);
	/* 为了程序处理方便起见，先构造一个链表头空结点 */
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while ( N-- ) {
		scanf("%d %d", &coef, &expon);
		Attach(coef, expon, &Rear); /* 将当前项插入多项式尾部 */
	}
	/* 删除临时生成的头结点 */
	t = P;  P = P->Next;  free(t);
	return P;
}

Polynomial Mult( Polynomial P1, Polynomial P2 )
{
	Polynomial P, Rear, t1, t2, t;
	int coef, expon;

	if (!P1 || !P2) return NULL;

	t1 = P1; t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while (t2) { /* 先用P1的第1项乘以P2，得到P */
		Attach(t1->Coef*t2->Coef, t1->Expon+t2->Expon, &Rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1) { /* 用P1的每一项乘以P2 */
		t2 = P2; Rear = P;
		while (t2) { /* P1与P2的两项相乘并插入P */
            /* 计算乘积项 */
			expon = t1->Expon + t2->Expon;
			coef = t1->Coef * t2->Coef;
            /* 找到合适的插入位置 */
			while (Rear->Next && Rear->Next->Expon > expon)
				Rear = Rear->Next;
            /* 如果P有指数相同的项，叠加 */
			if (Rear->Next && Rear->Next->Expon == expon) {
				if (Rear->Next->Coef + coef)
					Rear->Next->Coef += coef;
				else { /* 如果系数叠加后为0，则删除该项 */
					t = Rear->Next;
					Rear->Next = t->Next;
					free(t);
				}
			}
			else { /* P中没有指数相同项，插入新结点 */
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->Coef = coef; t->Expon = expon;
				t->Next = Rear->Next;
				Rear->Next = t; Rear = Rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
    /* 删除临时生成的头结点 */
	t = P;  P = P->Next;  free(t);

	return P;
}

void PrintPoly( Polynomial P )
{   /* 输出多项式 */
	if (!P) printf("0 0\n"); /* 输出零多项式 */
	else {
		printf("%d %d", P->Coef, P->Expon);
		P = P->Next;
		while ( P ) {
			printf(" %d %d", P->Coef, P->Expon);
			P = P->Next;
		}
		printf("\n");
	}
}

int main()
{
	Polynomial P1, P2, P;

	P1 = ReadPoly();
	P2 = ReadPoly();
	P = Mult( P1, P2 );
	PrintPoly( P );

	return 0;
}

