#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MAXID 6
#define MAXNAME 8
#define MAXN 100000

struct Student {
	char id[MAXID+1];
	char name[MAXNAME+1];
	int grade;
} Record[MAXN];

int ComparId(const void *a, const void *b)
{  /* 比较学号 */
   return strcmp(((const struct Student*)a)->id,
	             ((const struct Student*)b)->id);
}

int ComparName(const void *a, const void *b)
{   /* 比较姓名 */
	int k = strcmp(((const struct Student*)a)->name,
		           ((const struct Student*)b)->name);
	if (!k) /* 重名时按学号大小排序 */
		k = strcmp(((const struct Student*)a)->id,
		           ((const struct Student*)b)->id);
   return k;
}

int ComparGrade(const void *a, const void *b)
{   /* 比较成绩 */
	int k = (((const struct Student*)a)->grade > 
		     ((const struct Student*)b)->grade)? 1 : 0;
	if (!k) {
		k = (((const struct Student*)a)->grade <
			 ((const struct Student*)b)->grade)? -1 : 0;
		if (!k)  /* 成绩相同时按学号大小排序 */
			k = strcmp(((const struct Student*)a)->id,
			           ((const struct Student*)b)->id);
	}
	return k;
}

int main()
{
	int N, C, i;

	/* 读入数据 */
	scanf("%d %d", &N, &C);
	for (i=0; i<N; i++) {
		scanf("%s %s %d",Record[i].id, Record[i].name, &Record[i].grade);
	}
	/* 根据C选择相应的列进行排序 */
	switch (C) {
		case 1: qsort(Record, N, sizeof(struct Student), ComparId); break;
		case 2: qsort(Record, N, sizeof(struct Student), ComparName); break;
		case 3: qsort(Record, N, sizeof(struct Student), ComparGrade); break;
	}
	/* 输出数据 */
	for (i=0; i<N; i++) {
		printf("%s %s %d\n", Record[i].id, Record[i].name, Record[i].grade);
	}

	return 0;
}

