#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

//数据类型
typedef int QDataType;

//队列的结点
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QNode;

//队列的处于入的指针
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//队列初始化
void QueueInit(Queue* pq);

//队列销毁
void QueueDestory(Queue* pq);

//入队列
void QueuePush(Queue* pq, QDataType x);

//出队列
void QueuePop(Queue* pq);

//队列首元素
QDataType QueueFront(Queue* pq);

//队列尾元素
QDataType QueueBack(Queue* pq);

//队列是否为空
bool QueueEmpty(Queue* pq);

//队列元素个数
int QueueSize(Queue* pq);

