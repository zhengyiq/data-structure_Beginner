#pragma once

//��̬˳���

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


//��̬���ݱ�
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;
}SL;

void SLInit(SL* s);
void SLDestory(SL* s);
//β��βɾ
void SLPushBack(SL* s, SLDataType x);
void SLPopBack(SL* s);
void SLPrint(SL* ps);