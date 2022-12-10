#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//�ٶ�ջ�д洢����������Ϊint
typedef int STDataType;

//�����ʼ��ʱ������
#define DEFAULTY_CAPACITY 4

//֧�ֶ�̬������ջ
typedef struct Stack
{
	STDataType* _data;
	//ջ������
	int _capacity;
	//ջ�����±�
	int _top;
}Stack;

//ջ�ĳ�ʼ��
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, STDataType x);

// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);
