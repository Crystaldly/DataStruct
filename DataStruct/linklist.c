#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


//��һ��������ڵ��ڴ�ռ�
//�ڶ�������ֵ
//������������
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


/*β������ʵ�ֺ���*/
//��һ��������һ���½��
//�ڶ�����Ѱ��β��㣨�ؼ�һ����
//��������β������
int list_tail_insert(linklist H, data_t value)
{
	linklist p;
	linklist q;

	//����Ƿ�������
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

	//β�����ص�����Ϊ��
	//locate tail node //��λβ�ڵ�
	q = H;
	while (q->next != NULL) {
		q = q->next;
	}

	//insert
	//�ѽ������ҵ���β���ĺ���
	q->next = p;

	return 0;
}


/*�����������*/
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