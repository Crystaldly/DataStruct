#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


//第一步：申请节点内存空间
//第二步：赋值
//第三步：返回
linklist Llist_create()
{
	linklist H;

	H = (linklist)malloc(sizeof(listnode));
	if (H == NULL) {
		printf("malloc failed\n");
		return H;
	}
	H->data = 0;
	H->next = NULL;
	
	return H;
}


/*尾部插入实现函数*/
//第一步：建立一个新结点
//第二步：寻找尾结点（关键一步）
//第三步：尾部插入
int list_tail_insert(linklist H, data_t value)
{
	linklist p;
	linklist q;

	//检查是否有意义
	if (H == NULL) {
		printf("H is NULL");
		return  -1;
	}

	//new node
	if ((p = (linklist)malloc(sizeof(listnode))) == NULL) {
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;

	//尾结点的特点是它为空
	//locate tail node //定位尾节点
	q = H;
	while (q->next != NULL) {
		q = q->next;
	}

	//insert
	//把结点放在找到的尾结点的后面
	q->next = p;

	return 0;
}


/*链表遍历函数*/
int Llist_show(linklist H)
{
	linklist p;
	if (H == NULL) {
		printf("H is NULL\n");
		return -1;
	}

	p = H;
	while (p->next != NULL) {
		printf("%d ", p->next->data);
		p = p->next;
	}
	puts("");

	return 0;
}