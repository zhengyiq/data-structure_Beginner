#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
//产生一个链表
SListNode* CreateSList(SLTDateType n);

// 单链表打印
//void SListPrint_PP(const SListNode** pplist);
void SListPrint(SListNode* plist);

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);

// 单链表的尾删
void SListPopBack(SListNode** pplist);

// 单链表头删
void SListPopFront(SListNode** pplist);

// 单链表查找
//SListNode* SListFind_PP(const SListNode** pplist, SLTDateType x);
SListNode* SListFind(SListNode* plist, SLTDateType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
//void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
//void SListEraseAfter(SListNode* pos);

// 单链表的销毁
void SListDestroy(SListNode* plist);

// 在pos之前插入
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x);

// 在pos后面插入
void SListInsertAfter(SListNode* pos, SLTDateType x);

// 删除pos位置
void SListErase(SListNode** pplist, SListNode* pos);

// 删除pos后面位置
void SListEraseAfter(SListNode* pos);