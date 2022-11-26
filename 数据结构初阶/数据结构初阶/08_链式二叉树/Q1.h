#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

struct BinaryTreeNode;
//��������
typedef struct BinaryTreeNode* QDataType;

//���еĽ��
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QNode;

//���еĴ������ָ��
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//���г�ʼ��
void QueueInit(Queue* pq);

//��������
void QueueDestroy(Queue* pq);

//�����
void QueuePush(Queue* pq, QDataType x);

//������
void QueuePop(Queue* pq);

//������Ԫ��
QDataType QueueFront(Queue* pq);

//����βԪ��
QDataType QueueBack(Queue* pq);

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//����Ԫ�ظ���
int QueueSize(Queue* pq);

