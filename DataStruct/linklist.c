#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


//第一步：申请节点内存空间
//第二步：赋值
//第三步：返回
linklist Llist_create()
{
	linklist H;//定义一个指向H的链表指针，此时指针是一个空指针。

	H = (linklist)malloc(sizeof(listnode));//向内存申请一片空间，由于malloc的返回值为(void*)所以进行强制类型转换(linklist).
	if (H == NULL) { //对链表进行检查，查看空间是否申请成功。
		printf("malloc failed\n");
		return H;//内存没申请成功，返回当前链表的值，也就是NULL。
	}

	H->data = 0;//给链表中的数据赋值0
	H->next = NULL;//指向下一链表为空，代表此链表为第n-1个链表
	
	return H;//返回链表H
}


/*尾部插入实现函数*/
//第一步：建立一个新结点
//第二步：寻找尾结点（关键一步）
//第三步：尾部插入
/* 
* list_tail_insert:尾部插入链表
* pram: H->链表H，value->插入值
* @ret failed---1 succes--0
**/
int list_tail_insert(linklist H, data_t value)
{
	linklist p;
	linklist q;//定义两个链表

	//检查是否有意义
	if (H == NULL) {
		printf("H is NULL");
		return  -1;
	}

	//new node
	if ((p = (linklist)malloc(sizeof(listnode))) == NULL) { //申请新的空间，并创建新的结点
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;//进行赋值

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

/*获取结点函数*/
/*
* list_get:结点获取
* pram:H->链表，pos->位置
* @ret p->该结点的新链表
**/
linklist list_get(linklist H, int pos)
{
	linklist p;//定义链表
	int i;
	if (H == NULL) { //检查合法性
		printf("H is NULL\n");
		return NULL;
	}
	if (pos == -1) { 
		return H;
	}
	if (pos < -1) //输入错误
		return -1;

	p = H;
	i = -1;
	while ( i < pos)
	{
		p = p->next;//
		i++;
		if (p == NULL) { //传入函数的pos超过链表的实际长度
			printf("pos is invalid\n");
			return NULL;
		}
	}

	return p;
}


/*按位置插入*/
int Llist_insert(linklist H, data_t  value, int pos) 
{
	linklist p;
	linklist q;

	if (H == NULL) {
		printf("H is NULL");
		return -1;
	}
	//获取要插入位置的前一个位置
	p = list_get(H, pos - 1);
	if (p == NULL) {
		return -1;
	}
	
	//创建一个新的结点
	if ((q = (linklist)malloc(sizeof(listnode))) == NULL) {
		printf("malloc is failed");
		return -1;
	}
	q->data = value;
	q->next = NULL;

	//完成插入
	q->next = p->next;
	p->next = q;

	return 0;
}


/*删除某位置*/
int Llist_delete(linklist H, int pos)
{
	linklist p;
	linklist q;

	//检查函数的合法性
	if (H == NULL) {
		return -1;
	}

	//找要删除的前驱
	p = list_get(H, pos - 1);
	if (p == NULL) { //前驱为空指针
		return -1;
	}
	if (p->next == NULL) { //删除的是尾部 前驱为最后一个
		return -1;
	}

	//更正地址，链表
	q = p->next;
	p->next = q->next;

	//释放这个位置的内存，也就是删除它。
	free(q);
	q = NULL;

	return 0;
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

linklist Llist_free(linklist H)
{
	linklist p;

	if (H == NULL) {
		return NULL;
	}

	p = H;

	while (H != NULL) {
		p = H;
		H = H->next;
		free(p);
	}
	return NULL;
}