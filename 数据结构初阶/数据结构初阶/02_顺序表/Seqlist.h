#pragma once

//静态顺序表

#define N 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;
//}SL;

//void SLInit(SL s);
//void SLPushBack(SL s, SLDataType x);


//动态数据表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;
}SL;

void SLInit(SL* s);
void SLDestory(SL* s);
//顺序表尾插尾删
void SLPushBack(SL* s, SLDataType x);
void SLPopBack(SL* s);

//顺序表打印数据
void SLPrint(SL* ps);

//头插头删
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//检查顺序表的空间
void SLCheckCapacity(SL* ps);

//顺序表的查找
int SLFind_Single(SL* ps, SLDataType x);
//顺序表的连续查找
int SLFind_double(SL* ps, SLDataType x, int begin);

//顺序表在pos位置进行插入删除
void SLInsert(SL* ps, size_t pos, SLDataType x);
//void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, size_t pos);
//void SLErase(SL* ps, int pos);


