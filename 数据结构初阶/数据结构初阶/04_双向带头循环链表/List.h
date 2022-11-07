#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//定义数据变量类型
typedef int LTDataType;

//创建链表的结点的结构体
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}ListNode;

//链表结点的初始化
ListNode* ListNodeInit();

//创建链表的结点
ListNode* BuyListNode(LTDataType x);

//链表的尾插
void ListNodePushBack(ListNode* head, LTDataType x);

//链表的尾删
void ListNodePopBack(ListNode* head);

//链表打印
void ListNodePrint(ListNode* head);

//链表头插
void ListNodePushFront(ListNode* head, LTDataType x);

//链表头删
void ListNodePopFront(ListNode* head);

//链表数据查找
ListNode* ListNodeFind(ListNode* head, LTDataType x);

//在pos之前插入
void ListNodeInsert(ListNode* pos, LTDataType x);

//删除pos位置
void ListNodeErase(ListNode* pos);

//链表是否为空
bool ListNodeEmpty(ListNode* head);

//链表大小
size_t ListNodeSize(ListNode* head);

//链表销毁
void ListNodeDestroy(ListNode* head);




