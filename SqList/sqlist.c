#include <stdio.h>
#include "sqlist.h"
#include <stdlib.h>

/*list_create()�迼������*/
//��һ����Ҫ�����ڴ�洢���Ա�
//�ڶ��������Ա��Ա��ʼ��
//��������Ҫ�з���ֵ���������Ա�ĵ�ַ��
sqlink list_create()
{
	//malloc �����ݷŵ����� ��free֮ǰ���ݶ������
	sqlink L;

	L = (sqlink)malloc(sizeof(sqlist));
	if (L == NULL) {
		printf("list malloc failed");
		return L;//malloc�����ڴ�����ʧ�ܼ�ʱ�������L�����ؿգ���������Ա�Ϊ��
	}

	//init ��ʼ��
	memset(L, 0, sizeof(sqlist));//����
	L->last = -1;//ʹ�������һλ�±�Ϊ-1�����仰˵�������黹û���ɡ�

	//return ���ص�ַ
	return L;
}


/*���Ա��ÿ�*/
/*
* @ret 0-succes  -1-falied
**/
int list_clear(sqlink L)
{
	if (L == NULL)//������Ա�L�ĺϷ��ԣ����Ϊ�գ���ô��վ�û�����塣
		return -1;//��ʱ���أ�����ϵͳʧ�ܣ�ʹ����Ҫ�����½��С�

	memset(L, 0, sizeof(sqlist));//����
	L->last = -1;//ʹ�������һλ�±�Ϊ-1�����仰˵�������黹û���ɡ�

	return 0;
}


int list_free(sqlink L)
{
	if (L == NULL)
		return -1;
	
	free(L);//�ͷ��ڴ棬�����Ű�L������Ա�����
	L = NULL;//�����Ա�ָ���ÿգ���free(L)ֻ���ͷ��ڴ棬�����Ա�L���������ɴ��ڡ�

	return 0;
}

/*�ж����Ա��Ƿ�Ϊ��*/
/*
* list_empty:Is list empty?
* para L: list
* @ret 1-empty  0-not empty
**/
int list_empty(sqlink L)
{
	if (L->last == -1)
		return 1;
	else
		return 0;
}


int list_length(sqlink L)
{
	if (L == NULL)
		return -1;
	return (L->last + 1);
}

/*
* @ret -1-not exist pos
**/
//value�����Ա��е�λ��
int list_locate(sqlink L, data_t value)
{
	int i = 0;
	for (i = 0;i <= L->last;i++) {
		if (L->data[i] == value)
			return i;
	}
	return -1;
}


/*���Ա������Ҫ���ǵ�����*/
//��һ�������Ա�������
//�ڶ�����pos->[0,last+1],�����Ƿ���кϷ���
//�����������м����Ԫ��ʱ��Ԫ�ص��ƶ�����ǰ������׸��Ǻ�ߵ����ݡ����ԣ�Ӧ�ôӺ���ǰ�ƶ���
//���Ĳ�������ֵ��last++�����ݴ�ֵ���ṹ���Ա���¡�
int list_insert(sqlink L, data_t value, int pos)
{
	//full��
	if (L->last == N - 1) {
		printf("list is full\n");
		return -1;
	}

	//check ���� pos 0 <= pos <= last+1 posӦ����[0,last+1]֮��
	if (pos < 0 || pos > L->last + 1) {
		printf("Pos is invalid\n");
		return -1;
	}

	//move Ԫ��
	for (int i = L->last; i >= pos; i--) {
		L->data[i + 1] = L->data[i];
	}

	//updata last
	L->data[pos] = value;//����ֵ����±�Ϊpos��λ��
	L->last++;//���һλ�±�+1���������Ա��������Ԫ�ء�

	return 0;
}
/*ɾ�����Ա��е�һ��Ԫ��*/
//��һ�������ǿձ����ݵĺϷ��� pos->[0,last]
//�ڶ�����Ԫ������ǰ�ƶ���
//���������������Ա�ĳ�Ա��last--��
int list_delete(sqlink L, int pos)
{
	if (L->last == -1) {
		printf("List is empty\n");
		return -1;
	}
	
	//pos [0,last]
	if (pos < 0 || pos > L->last) {
		printf("delete is invalid\n");
		return -1;
	}

	//move [pos+1,last]
	for (int i = pos + 1;i <= L->last;i++) {
		L->data[i - 1] = L->data[i];
	}

	//update
	L->last--;

	return 0;
}

/*�ϲ��������Ա�*/
int list_merge(sqlink L1, sqlink L2)
{
	int i = 0;
	int ret;

	while (i <= L2->last) {
		ret = list_locate(L1,L2->data[i]);
		if (ret == -1) {
			if (list_insert(L1, L2->data[i], L1->last + 1) == -1)
				return -1;
		}

		i++;
	}
	return 0;
}


/*ɾ���ظ�Ԫ��*/
int list_purge(sqlink L)
{
	int i;
	int j;
	if(L->last == 0)
	return 0;

	i = 1;
	while (i <= L->last) {
		j = i - 1;
		while (j >= 0) {
			if (L->data[i] == L->data[j]) {
				list_delete(L, i);
				break;
			}
			else {
				j--;
			}
		}
		if (j < 0) {
			i++;
		}
	}
	return 0;
}


int list_show(sqlink L)
{
	if (L == NULL)
		return -1;

	if (L->last == -1)
		printf("List is empty\n");

	for (int i = 0; i <= L->last; i++) {
		printf("%d ", L->data[i]);
	}
	puts("");//����
	return 0;
}
