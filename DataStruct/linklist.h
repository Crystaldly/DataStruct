#ifndef __linklist_H__
#define __linklist_H__

typedef int data_t;

typedef struct node {
	data_t data;
	struct node* next;
}listnode,*linklist;

linklist Llist_create();//创建链表
int list_tail_insert(linklist H,data_t value);//尾部插入
linklist list_get(linklist H, int pos);//获取链表中某一结点
int Llist_insert(linklist H, data_t  value, int pos);//按位置插入
int Llist_delete(linklist H, int pos);//删除某位置结点
int Llist_show(linklist H);
linklist Llist_free(linklist H);//释放内存


#endif

