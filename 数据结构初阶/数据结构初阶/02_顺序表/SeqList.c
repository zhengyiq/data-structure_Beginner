#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

//顺序表初始化
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//顺序表销毁
void SLDestory(SL* ps)
{
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = 0;
		ps->capacity = 0;
	}
}

//顺序表尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//顺序表尾删
void SLPopBack(SL* ps)
{
	//温柔的检查
	//if (ps->size)
	//{
	//	return 0;
	//}
	//暴力检查
	assert(ps->size > 0);
	ps->size--;
}
 
//顺序表打印
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//顺序表检查容量
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (NULL == tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//顺序表头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end > -1)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[end + 1] = x;
	ps->size++;
}

//顺序表头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);//如果size指向0，那么同样会产生越界
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

//顺序表的查找
int SLFind_Single(SL* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

//顺序表的连续查找
int SLFind_double(SL* ps, SLDataType x, int begin)
{
	assert(ps);
	for (size_t i = begin; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

//顺序表在pos位置处插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
//void SLInsert(SL* ps, size_t pos, SLDataType x)
//{
//	assert(ps);
//	assert(pos >= 0);
//	assert(pos <= ps->size);
//	SLCheckCapacity(ps);
//	size_t end = ps->size - 1;
//	while (end >= pos)
//	{
//		ps->a[end + 1] = ps->a[end];
//		if (end == 0)
//			break;//使用size_t要注意算术转换的问题
//		end--;
//	}
//	ps->a[pos] = x;
//	ps->size++;
//}

//顺序表在pos位置处删除
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);
	//int right = pos + 1;
	while (pos < ps->size)
	{
		ps->a[pos] = ps->a[pos + 1];
		pos++;
	}
	ps->size--;
}
//void SLErase(SL* ps, size_t pos)
//{
//	assert(ps);
//	assert(pos >= 0);
//	assert(pos < ps->size);
//	//int right = pos + 1;
//	while (pos < ps->size)
//	{
//		ps->a[pos] = ps->a[pos + 1];
//		pos++;
//	}
//	ps->size--;
//}
