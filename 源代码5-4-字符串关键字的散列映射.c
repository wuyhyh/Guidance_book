#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXS 8 /* 最大字符串长度 */
#define MAXD 3 /* 参与散列映射计算的字符个数 */
#define MAXB 5 /* 每个字符占的位数 */
#define Mask ((1<<(MAXD*MAXB))-1) /* 掩码 */

/*--- 简化版散列表定义及初始化 ---*/

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
{ /* 字符串Key最后D位移位法散列函数 */
	int h = 0;
	while ( *Key != '\0' )
		h = (h<<MAXB) + (*Key++ - 'A');
	return ((h&Mask) % P);
}

int Find ( HashTable H, char *Key )
{ /* 返回Key的位置，或者是适合插入Key的位置 */
	int inc, Cnt = 0; /* 冲突次数 */
	int Next, Pos;

	Next = Pos = Hash(Key, H->TableSize);
	/* 先找到散列映射后的位置 */

	while ((H->TheCells[Next].Info != Empty) &&
		(strcmp(H->TheCells[Next].Element, Key))) {
	/* 若该位置已经被其它关键字占用 */
		/* 根据冲突发生的奇偶次计算探测步长 */
		if (++Cnt%2)  /* 奇数次冲突 */
			inc = ((Cnt+1)*(Cnt+1))>>2;
		else  /* 偶数次冲突 */
			inc = -(Cnt*Cnt)>>2;
		Next = Pos + inc; /* 平方探测 */
		if (Next < 0) Next += H->TableSize;
		else if (Next >= H->TableSize)
			Next -= H->TableSize;
	}
	return Next;
}

void InsertAndOutput ( char *Key, HashTable H )
{
	int Pos = Find( H, Key );
	/* 找到Key的位置，或者是适合插入Key的位置 */

	if (H->TheCells[Pos].Info == Empty) { /* 插入 */
		H->TheCells[Pos].Info = Legitimate;
		strcpy(H->TheCells[Pos].Element, Key);
	}

	/* 输出 */
	printf("%d", Pos);
}

int main()
{
	int N, P, i;
	ElementType Key;
	HashTable H;

	scanf("%d %d", &N, &P);
	H = InitializeTable (P); /* 创建一个散列表 */

	scanf("%s", Key);
	InsertAndOutput(Key, H); /* 输出第1个关键字的位置 */
	for (i=1; i<N; i++) {
		scanf("%s", Key);
		printf(" "); /* 后续输出数字之前有空格 */
		InsertAndOutput(Key, H);
	}
	printf("\n");

	return 0;
}

