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
	sqlink L;//创建结构体指针L，不占空间，要给线性表一段空间。

	L = list_create();
	if (L == NULL)
		return;

	list_insert(L, 10, 0);
	list_show(L);
}