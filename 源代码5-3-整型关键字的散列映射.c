#include<stdio.h>
#include<stdlib.h>

/*------------- �򻯰�ɢ�б��弰��ʼ�� -------------*/

typedef int ElementType;
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
	H->TheCells = malloc( sizeof(struct HashEntry)
		                  * H->TableSize );
	while (TableSize)
		H->TheCells[--TableSize].Info = Empty;
	return H;
}

/*----------------------------------------------------*/

int Hash ( ElementType Key, int P )
{ /* ����������ɢ�к��� */
	return Key%P;
}

int Find ( HashTable H, ElementType Key )
{ /* ����Key��λ�ã��������ʺϲ���Key��λ�� */
	int Pos = Hash(Key, H->TableSize);
	/* ���ҵ�ɢ��ӳ����λ�� */
	while ((H->TheCells[Pos].Info != Empty) &&
		(H->TheCells[Pos].Element != Key)) {
	/* ����λ���Ѿ��������ؼ���ռ�� */
		Pos ++; /* ����̽����һ��λ�� */
		if (Pos == H->TableSize)
			Pos -= H->TableSize;
	}
	return Pos;
}

void InsertAndOutput ( ElementType Key, HashTable H )
{
	int Pos = Find( H, Key );
	/* �ҵ�Key��λ�ã��������ʺϲ���Key��λ�� */
	if (H->TheCells[Pos].Info == Empty) { /* ���� */
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}

	/* ��� */
	printf("%d", Pos);
}

int main()
{
	int N, P, Key, i;
	HashTable H;

	scanf("%d %d", &N, &P);
	H = InitializeTable (P); /* ����һ��ɢ�б� */

	scanf("%d", &Key);
	InsertAndOutput(Key, H); /* �����1���ؼ��ֵ�λ�� */
	for (i=1; i<N; i++) {
		scanf("%d", &Key);
		printf(" "); /* �����������֮ǰ�пո� */
		InsertAndOutput(Key, H);
	}
	printf("\n");

	return 0;
}

