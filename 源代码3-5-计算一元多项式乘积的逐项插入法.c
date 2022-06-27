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
{   /* ����(coef, expon)���ɵ�������뵽PtrRear���ָ��Ľ����� */
	Polynomial P;

	P = (Polynomial)malloc(sizeof(struct PolyNode));  /* ����һ�½�� */
	P->Coef = coef;    /* ���½�㸳ֵ  */
	P->Expon = expon;
	P->Next = NULL;
	(*PtrRear)->Next = P; /* ��Pָ���������뵽��ǰ������ʽβ��ĺ��� */
	*PtrRear = P;         /* �޸�PtrRearֵ */
}

Polynomial ReadPoly()
{   /* ���벢��������ʽ */
	Polynomial  P, Rear, t;
	int coef, expon, N;

	scanf("%d", &N);
	/* Ϊ�˳�������������ȹ���һ������ͷ�ս�� */
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Next = NULL;
	Rear = P;
	while ( N-- ) {
		scanf("%d %d", &coef, &expon);
		Attach(coef, expon, &Rear); /* ����ǰ��������ʽβ�� */
	}
	/* ɾ����ʱ���ɵ�ͷ��� */
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
	while (t2) { /* ����P1�ĵ�1�����P2���õ�P */
		Attach(t1->Coef*t2->Coef, t1->Expon+t2->Expon, &Rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1) { /* ��P1��ÿһ�����P2 */
		t2 = P2; Rear = P;
		while (t2) { /* P1��P2��������˲�����P */
            /* ����˻��� */
			expon = t1->Expon + t2->Expon;
			coef = t1->Coef * t2->Coef;
            /* �ҵ����ʵĲ���λ�� */
			while (Rear->Next && Rear->Next->Expon > expon)
				Rear = Rear->Next;
            /* ���P��ָ����ͬ������� */
			if (Rear->Next && Rear->Next->Expon == expon) {
				if (Rear->Next->Coef + coef)
					Rear->Next->Coef += coef;
				else { /* ���ϵ�����Ӻ�Ϊ0����ɾ������ */
					t = Rear->Next;
					Rear->Next = t->Next;
					free(t);
				}
			}
			else { /* P��û��ָ����ͬ������½�� */
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->Coef = coef; t->Expon = expon;
				t->Next = Rear->Next;
				Rear->Next = t; Rear = Rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
    /* ɾ����ʱ���ɵ�ͷ��� */
	t = P;  P = P->Next;  free(t);

	return P;
}

void PrintPoly( Polynomial P )
{   /* �������ʽ */
	if (!P) printf("0 0\n"); /* ��������ʽ */
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

