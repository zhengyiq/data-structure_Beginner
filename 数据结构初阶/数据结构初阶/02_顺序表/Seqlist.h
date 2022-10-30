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
//˳���β��βɾ
void SLPushBack(SL* s, SLDataType x);
void SLPopBack(SL* s);

//˳����ӡ����
void SLPrint(SL* ps);

//ͷ��ͷɾ
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//���˳���Ŀռ�
void SLCheckCapacity(SL* ps);

//˳���Ĳ���
int SLFind_Single(SL* ps, SLDataType x);
//˳������������
int SLFind_double(SL* ps, SLDataType x, int begin);

//˳�����posλ�ý��в���ɾ��
void SLInsert(SL* ps, size_t pos, SLDataType x);
//void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, size_t pos);
//void SLErase(SL* ps, int pos);


