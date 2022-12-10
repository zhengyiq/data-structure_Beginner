#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//假定栈中存储的数据类型为int
typedef int STDataType;

//定义初始化时的容量
#define DEFAULTY_CAPACITY 4

//支持动态增长的栈
typedef struct Stack
{
	STDataType* _data;
	//栈的容量
	int _capacity;
	//栈顶的下标
	int _top;
}Stack;

//栈的初始化
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType x);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);
