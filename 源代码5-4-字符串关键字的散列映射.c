#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXS 8 /* ����ַ������� */
#define MAXD 3 /* ����ɢ��ӳ�������ַ����� */
#define MAXB 5 /* ÿ���ַ�ռ��λ�� */
#define Mask ((1<<(MAXD*MAXB))-1) /* ���� */

/*--- �򻯰�ɢ�б��弰��ʼ�� ---*/

typedef char ElementType[MAXS+1];
enum EntryType { Legitimate, Empty };

struct HashEntry {
	ElementType Element;
	enum EntryType Info;
};

struct HashTbl {
	int TableSize;
	struct HashEntry *TheCells;
};

typedef struct HashTbl *HashTable;

HashTable InitializeTable ( int TableSize )
{
	HashTable H = malloc( sizeof(struct HashTbl) );
	H->TableSize = TableSize;
	H->TheCells = malloc( sizeof(struct HashEntry) * H->TableSize );
	while (TableSize)
		H->TheCells[--TableSize].Info = Empty;
	return H;
}

/*---------------------------------*/

int Hash ( char *Key, int P )
{ /* �ַ���Key���Dλ��λ��ɢ�к��� */
	int h = 0;
	while ( *Key != '\0' )
		h = (h<<MAXB) + (*Key++ - 'A');
	return ((h&Mask) % P);
}

int Find ( HashTable H, char *Key )
{ /* ����Key��λ�ã��������ʺϲ���Key��λ�� */
	int inc, Cnt = 0; /* ��ͻ���� */
	int Next, Pos;

	Next = Pos = Hash(Key, H->TableSize);
	/* ���ҵ�ɢ��ӳ����λ�� */

	while ((H->TheCells[Next].Info != Empty) &&
		(strcmp(H->TheCells[Next].Element, Key))) {
	/* ����λ���Ѿ��������ؼ���ռ�� */
		/* ���ݳ�ͻ��������ż�μ���̽�ⲽ�� */
		if (++Cnt%2)  /* �����γ�ͻ */
			inc = ((Cnt+1)*(Cnt+1))>>2;
		else  /* ż���γ�ͻ */
			inc = -(Cnt*Cnt)>>2;
		Next = Pos + inc; /* ƽ��̽�� */
		if (Next < 0) Next += H->TableSize;
		else if (Next >= H->TableSize)
			Next -= H->TableSize;
	}
	return Next;
}

void InsertAndOutput ( char *Key, HashTable H )
{
	int Pos = Find( H, Key );
	/* �ҵ�Key��λ�ã��������ʺϲ���Key��λ�� */

	if (H->TheCells[Pos].Info == Empty) { /* ���� */
		H->TheCells[Pos].Info = Legitimate;
		strcpy(H->TheCells[Pos].Element, Key);
	}

	/* ��� */
	printf("%d", Pos);
}

int main()
{
	int N, P, i;
	ElementType Key;
	HashTable H;

	scanf("%d %d", &N, &P);
	H = InitializeTable (P); /* ����һ��ɢ�б� */

	scanf("%s", Key);
	InsertAndOutput(Key, H); /* �����1���ؼ��ֵ�λ�� */
	for (i=1; i<N; i++) {
		scanf("%s", Key);
		printf(" "); /* �����������֮ǰ�пո� */
		InsertAndOutput(Key, H);
	}
	printf("\n");

	return 0;
}

