#include <stdio.h>
#include "sqlist.h"

void test_insert();

int main()
{
	test_insert();

	return 0;
}

void test_insert()
{
	sqlink L;//�����ṹ��ָ��L����ռ�ռ䣬Ҫ�����Ա�һ�οռ䡣

	L = list_create();
	if (L == NULL)
		return;

	list_insert(L, 10, 0);
	list_show(L);
}