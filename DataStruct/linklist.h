#ifndef __linklist_H__
#define __linklist_H__

typedef int data_t;

typedef struct node {
	data_t data;
	struct node* next;
}listnode,*linklist;

linklist Llist_create();
int list_tail_insert(linklist H,data_t value);//Î²²¿²åÈë
int Llist_show(linklist H);

#endif

