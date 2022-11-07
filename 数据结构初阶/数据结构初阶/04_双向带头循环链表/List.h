#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//�������ݱ�������
typedef int LTDataType;

//��������Ľ��Ľṹ��
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;

//������ĳ�ʼ��
ListNode* ListNodeInit();

//��������Ľ��
ListNode* BuyListNode(LTDataType x);

//�����β��
void ListNodePushBack(ListNode* head, LTDataType x);

//�����βɾ
void ListNodePopBack(ListNode* head);

//�����ӡ
void ListNodePrint(ListNode* head);

//����ͷ��
void ListNodePushFront(ListNode* head, LTDataType x);

//����ͷɾ
void ListNodePopFront(ListNode* head);

//�������ݲ���
ListNode* ListNodeFind(ListNode* head, LTDataType x);

//��pos֮ǰ����
void ListNodeInsert(ListNode* pos, LTDataType x);

//ɾ��posλ��
void ListNodeErase(ListNode* pos);

//�����Ƿ�Ϊ��
bool ListNodeEmpty(ListNode* head);

//�����С
size_t ListNodeSize(ListNode* head);

//��������
void ListNodeDestroy(ListNode* head);




