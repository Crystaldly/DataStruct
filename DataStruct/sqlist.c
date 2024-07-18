#include <stdio.h>
#include "sqlist.h"
#include <stdlib.h>

/*list_create()需考虑问题*/
//第一步，要申请内存存储线性表
//第二步，线性表成员初始化
//第三步，要有返回值，返回线性表的地址。
sqlink list_create()
{
	//malloc 把数据放到堆上 不free之前数据都存会在
	sqlink L;

	L = (sqlink)malloc(sizeof(sqlist));
	if (L == NULL) {
		printf("list malloc failed");
		return L;//malloc创建内存申请失败及时返回这个L，返回空，则这个线性表为空
	}

	//init 初始化
	memset(L, 0, sizeof(sqlist));//清零
	L->last = -1;//使数组最后一位下标为-1，换句话说就是数组还没生成。

	//return 返回地址
	return L;
}


/*线性表置空*/
/*
* @ret 0-succes  -1-falied
**/
int list_clear(sqlink L)
{
	if (L == NULL)//检查线性表L的合法性，如果为空，那么清空就没有意义。
		return -1;//及时返回，告诉系统失败，使程序不要再向下进行。

	memset(L, 0, sizeof(sqlist));//清零
	L->last = -1;//使数组最后一位下标为-1，换句话说就是数组还没生成。

	return 0;
}


int list_delete(sqlink L)
{
	if (L == NULL)
		return -1;
	
	free(L);//释放内存，代表着把L这个线性表销毁
	L = NULL;//把线性表指针置空，因free(L)只是释放内存，但线性表L的内容依旧存在。

	return 0;
}

/*判断线性表是否为空*/
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


int list_locate(sqlink L, data_t value)
{
	return 0;
}


/*线性表插入需要考虑的问题*/
//第一步，线性表满了吗？
//第二步，pos->[0,last+1],数据是否具有合法性
//第三步，在中间插入元素时。元素的移动，从前向后，容易覆盖后边的数据。所以，应该从后往前移动。
//第四步，存新值，last++。数据存值，结构体成员更新。
int list_insert(sqlink L, data_t value, int pos)
{
	//full？
	if (L->last == N - 1) {
		printf("list is full\n");
		return -1;
	}

	//check 参数 pos 0 <= pos <= last+1 pos应该在[0,last+1]之间
	if (pos < 0 || pos > L->last + 1) {
		printf("Pos is invalid\n");
		return -1;
	}

	//move 元素
	for (int i = L->last; i >= pos; i--) {
		L->data[i + 1] = L->data[i];
	}

	//updata last
	L->data[pos] = value;//将新值存进下标为pos的位置
	L->last++;//最后一位下标+1，代表线性表插入了新元素。

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
	puts("");//换行
	return 0;
}
