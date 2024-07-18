#ifndef __sqlist_H__
#define __sqlist_H__

#include <stdio.h>
#include "sqlist.h"

typedef int data_t;
#define N 128

typedef struct {
	data_t data[N];
	int last;
}sqlist, *sqlink;

sqlink list_create();//˳���Ĵ���
int list_clear(sqlink L);//���Ա��ÿ�
int list_delete(sqlink L);//���Ա�����
int list_empty(sqlink L);//���˳����Ƿ�Ϊ��
int list_length(sqlink L);//˳���ĳ���
int list_locate(sqlink L, data_t value);//˳������λ��
int list_insert(sqlink L, data_t value, int pos);//˳������
int list_show(sqlink L);//���Ա����


#endif

