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
{  /* �Ƚ�ѧ�� */
   return strcmp(((const struct Student*)a)->id,
	             ((const struct Student*)b)->id);
}

int ComparName(const void *a, const void *b)
{   /* �Ƚ����� */
	int k = strcmp(((const struct Student*)a)->name,
		           ((const struct Student*)b)->name);
	if (!k) /* ����ʱ��ѧ�Ŵ�С���� */
		k = strcmp(((const struct Student*)a)->id,
		           ((const struct Student*)b)->id);
   return k;
}

int ComparGrade(const void *a, const void *b)
{   /* �Ƚϳɼ� */
	int k = (((const struct Student*)a)->grade > 
		     ((const struct Student*)b)->grade)? 1 : 0;
	if (!k) {
		k = (((const struct Student*)a)->grade <
			 ((const struct Student*)b)->grade)? -1 : 0;
		if (!k)  /* �ɼ���ͬʱ��ѧ�Ŵ�С���� */
			k = strcmp(((const struct Student*)a)->id,
			           ((const struct Student*)b)->id);
	}
	return k;
}

int main()
{
	int N, C, i;

	/* �������� */
	scanf("%d %d", &N, &C);
	for (i=0; i<N; i++) {
		scanf("%s %s %d",Record[i].id, Record[i].name, &Record[i].grade);
	}
	/* ����Cѡ����Ӧ���н������� */
	switch (C) {
		case 1: qsort(Record, N, sizeof(struct Student), ComparId); break;
		case 2: qsort(Record, N, sizeof(struct Student), ComparName); break;
		case 3: qsort(Record, N, sizeof(struct Student), ComparGrade); break;
	}
	/* ������� */
	for (i=0; i<N; i++) {
		printf("%s %s %d\n", Record[i].id, Record[i].name, Record[i].grade);
	}

	return 0;
}

