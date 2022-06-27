#include<stdio.h>
#include<stdlib.h>

/*------------- 简化版散列表定义及初始化 -------------*/

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
{ /* 除留余数法散列函数 */
	return Key%P;
}

int Find ( HashTable H, ElementType Key )
{ /* 返回Key的位置，或者是适合插入Key的位置 */
	int Pos = Hash(Key, H->TableSize);
	/* 先找到散列映射后的位置 */
	while ((H->TheCells[Pos].Info != Empty) &&
		(H->TheCells[Pos].Element != Key)) {
	/* 若该位置已经被其它关键字占用 */
		Pos ++; /* 线性探测下一个位置 */
		if (Pos == H->TableSize)
			Pos -= H->TableSize;
	}
	return Pos;
}

void InsertAndOutput ( ElementType Key, HashTable H )
{
	int Pos = Find( H, Key );
	/* 找到Key的位置，或者是适合插入Key的位置 */
	if (H->TheCells[Pos].Info == Empty) { /* 插入 */
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}

	/* 输出 */
	printf("%d", Pos);
}

int main()
{
	int N, P, Key, i;
	HashTable H;

	scanf("%d %d", &N, &P);
	H = InitializeTable (P); /* 创建一个散列表 */

	scanf("%d", &Key);
	InsertAndOutput(Key, H); /* 输出第1个关键字的位置 */
	for (i=1; i<N; i++) {
		scanf("%d", &Key);
		printf(" "); /* 后续输出数字之前有空格 */
		InsertAndOutput(Key, H);
	}
	printf("\n");

	return 0;
}

