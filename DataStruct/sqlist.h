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

sqlink list_create();//顺序表的创建
int list_clear(sqlink L);//线性表置空
int list_free(sqlink L);//线性表销毁
int list_empty(sqlink L);//检查顺序表是否为空
int list_length(sqlink L);
int list_locate(sqlink L, data_t value);
int list_insert(sqlink L, data_t value, int pos);//顺序表插入
int list_delete(sqlink L, int pos);//线性表删除一个元素
int list_merge(sqlink L1, sqlink L2);//将两个表进行合并
int list_purge(sqlink L);//删除线性表中的重复元素
int list_show(sqlink L);//线性表遍历


#endif

