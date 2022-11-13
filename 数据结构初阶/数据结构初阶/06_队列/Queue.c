#include "Queue.h"

//���г�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//��������
void QueueDestory(Queue* pq)
{
	assert(pq);

	while (pq->head != NULL)
	{
		QNode* del = pq->head;
		pq->head = pq->head->_next;
		free(del);
	}

	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//�����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	if (pq->head == NULL)
	{
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		if (newnode == NULL)
		{
			perror("malloc failed");
			exit(-1);
		}
		newnode->_data = x;
		pq->head = newnode; 
		pq->tail = newnode;
		pq->tail->_next = NULL;
	}
	else
	{
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		if (newnode == NULL)
		{
			perror("malloc failed");
			exit(-1);
		}
		newnode->_data = x;
		pq->tail->_next = newnode;
		pq->tail = pq->tail->_next;
		pq->tail->_next = NULL;
	}

	pq->size++;
}

//������
void QueuePop(Queue* pq)
{
	assert(pq);
	//assert(pq->head != NULL);
	assert(!QueueEmpty(pq));

	Queue* del = pq->head;
	pq->head = pq->head->_next;
	free(del);

	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}

	pq->size--;
}

//������Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	//assert(pq->head != NULL);
	assert(!QueueEmpty(pq));

	return pq->head->_data;
}

//����βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	//assert(pq->head != NULL);
	assert(!QueueEmpty(pq));

	return pq->tail->_data;
}

//�����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	
	return pq->head == NULL && pq->tail == NULL;
}

//����Ԫ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}