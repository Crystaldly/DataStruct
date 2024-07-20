#ifndef __linklist_H__
#define __linklist_H__

typedef int data_t;

typedef struct node {
	data_t data;
	struct node* next;
}listnode,*linklist;

linklist Llist_create();//��������
int list_tail_insert(linklist H,data_t value);//β������
linklist list_get(linklist H, int pos);//��ȡ������ĳһ���
int Llist_insert(linklist H, data_t  value, int pos);//��λ�ò���
int Llist_delete(linklist H, int pos);//ɾ��ĳλ�ý��
int Llist_show(linklist H);
linklist Llist_free(linklist H);//�ͷ��ڴ�


#endif

