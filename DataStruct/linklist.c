#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


//��һ��������ڵ��ڴ�ռ�
//�ڶ�������ֵ
//������������
linklist Llist_create()
{
	linklist H;//����һ��ָ��H������ָ�룬��ʱָ����һ����ָ�롣

	H = (linklist)malloc(sizeof(listnode));//���ڴ�����һƬ�ռ䣬����malloc�ķ���ֵΪ(void*)���Խ���ǿ������ת��(linklist).
	if (H == NULL) { //��������м�飬�鿴�ռ��Ƿ�����ɹ���
		printf("malloc failed\n");
		return H;//�ڴ�û����ɹ������ص�ǰ�����ֵ��Ҳ����NULL��
	}

	H->data = 0;//�������е����ݸ�ֵ0
	H->next = NULL;//ָ����һ����Ϊ�գ����������Ϊ��n-1������
	
	return H;//��������H
}


/*β������ʵ�ֺ���*/
//��һ��������һ���½��
//�ڶ�����Ѱ��β��㣨�ؼ�һ����
//��������β������
/* 
* list_tail_insert:β����������
* pram: H->����H��value->����ֵ
* @ret failed---1 succes--0
**/
int list_tail_insert(linklist H, data_t value)
{
	linklist p;
	linklist q;//������������

	//����Ƿ�������
	if (H == NULL) {
		printf("H is NULL");
		return  -1;
	}

	//new node
	if ((p = (linklist)malloc(sizeof(listnode))) == NULL) { //�����µĿռ䣬�������µĽ��
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;//���и�ֵ

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

/*��ȡ��㺯��*/
/*
* list_get:����ȡ
* pram:H->����pos->λ��
* @ret p->�ý���������
**/
linklist list_get(linklist H, int pos)
{
	linklist p;//��������
	int i;
	if (H == NULL) { //���Ϸ���
		printf("H is NULL\n");
		return NULL;
	}
	if (pos == -1) { 
		return H;
	}
	if (pos < -1) //�������
		return -1;

	p = H;
	i = -1;
	while ( i < pos)
	{
		p = p->next;//
		i++;
		if (p == NULL) { //���뺯����pos���������ʵ�ʳ���
			printf("pos is invalid\n");
			return NULL;
		}
	}

	return p;
}


/*��λ�ò���*/
int Llist_insert(linklist H, data_t  value, int pos) 
{
	linklist p;
	linklist q;

	if (H == NULL) {
		printf("H is NULL");
		return -1;
	}
	//��ȡҪ����λ�õ�ǰһ��λ��
	p = list_get(H, pos - 1);
	if (p == NULL) {
		return -1;
	}
	
	//����һ���µĽ��
	if ((q = (linklist)malloc(sizeof(listnode))) == NULL) {
		printf("malloc is failed");
		return -1;
	}
	q->data = value;
	q->next = NULL;

	//��ɲ���
	q->next = p->next;
	p->next = q;

	return 0;
}


/*ɾ��ĳλ��*/
int Llist_delete(linklist H, int pos)
{
	linklist p;
	linklist q;

	//��麯���ĺϷ���
	if (H == NULL) {
		return -1;
	}

	//��Ҫɾ����ǰ��
	p = list_get(H, pos - 1);
	if (p == NULL) { //ǰ��Ϊ��ָ��
		return -1;
	}
	if (p->next == NULL) { //ɾ������β�� ǰ��Ϊ���һ��
		return -1;
	}

	//������ַ������
	q = p->next;
	p->next = q->next;

	//�ͷ����λ�õ��ڴ棬Ҳ����ɾ������
	free(q);
	q = NULL;

	return 0;
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