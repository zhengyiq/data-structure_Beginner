#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

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

void SLPushBack(SL* ps, SLDataType x)
void SLPushBack(SL* ps, SLDataType x)
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
	ps->a[ps->size] = x;
	ps->size++;
}

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
 
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}