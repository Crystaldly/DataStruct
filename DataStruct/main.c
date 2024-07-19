#include <stdio.h>
#include "sqlist.h"
#include "linklist.h"

void test_insert();
void test_delete();
void test_merge();
void test_purge();
int main()
{
	//test_insert();
	//test_delete();
	//test_merge();
	//void test_purge();

	linklist H;
	int value;

	H = Llist_create();
	if (H == NULL)
		return -1;

	printf("input:");
	while (1) {
		scanf_s("%d", &value);
		if (value == 1)
			break;
		list_tail_insert(H, value);
		printf("input:");
	}
	Llist_show(H);

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
void test_delete()
{
	sqlink L;//创建结构体指针L，不占空间，要给线性表一段空间。

	L = list_create();
	if (L == NULL)
		return;
	list_insert(L, 10, 0);
	list_show(L);
	list_insert(L, 20, 0);
	list_show(L);

	list_delete(L, 0);
	list_show(L);
	list_free(L);
	list_show(L);

}
void test_merge()
{
	sqlink L1, L2;

	L1 = list_create();
	L2 = list_create();
	if ((L1 == NULL) ||(L2==NULL))
		return;
	list_insert(L1, 10, 0);
	list_show(L1);
	list_insert(L2, 20, 0);
	list_show(L2);

	list_merge(L1, L2);
	list_show(L1);
	list_show(L2);
	list_free(L1);
	list_free(L2);
	
}
void test_purge()
{
	sqlink L;//创建结构体指针L，不占空间，要给线性表一段空间。

	L = list_create();
	if (L == NULL)
		return;

	list_insert(L, 10, 0);
	list_insert(L, 9, 0);
	list_insert(L, 10, 0);
	list_insert(L, 8, 0);
	list_show(L);
	list_purge(L);
	list_show(L);
}