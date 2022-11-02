#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* ptmp = (SListNode*)malloc(sizeof(SListNode));
	if (ptmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ptmp->data = x;
	ptmp->next = NULL;
	return ptmp;
}

// 单链表打印
void SListPrint(const SListNode** pplist)
{
	//assert(plist);
	while (*pplist != NULL)
	{
		printf("%d ", (*pplist)->data);
		*pplist = (*pplist)->next;
	}
	//printf("NULL");
}

//产生一个链表
SListNode* CreateSList(SLTDateType n)
{
	SListNode* phead = NULL;
	SListNode* ptail = NULL;
	SListNode* newnode = NULL;

	for (int i = 0; i < n; i++)
	{
		if (phead == NULL)
		{
			ptail = phead = BuySListNode(i);

		}
		else
		{
			newnode = BuySListNode(i);
			ptail->next = newnode;
			ptail = newnode;
		}
	}
	return phead;
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* phead = *pplist;
	SListNode* ptmp = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = ptmp;
	}
	else
	{
		while (phead->next != NULL)
		{
			phead = phead->next;
		}
		phead->next = ptmp;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* phead = *pplist;
	//if (*pplist == NULL)
	//{
	//	SListNode* ptmp = BuySListNode(x);
	//	*pplist = ptmp;
	//}
	//else
	//{
		SListNode* ptmp = BuySListNode(x);
		ptmp->next = phead;
		*pplist = ptmp;
//	}
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* phead = *pplist;
	SListNode* ptail = phead->next;
	if (phead->next == NULL)
	{
		free(phead);
		*pplist = NULL;
		return;
	}
	while (ptail->next != NULL)
	{
		ptail = ptail->next;
		phead = phead->next;
	}
	phead->next = NULL;
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* phead = *pplist;
	if (phead == NULL)
	{
		free(phead);
		*pplist = NULL;
		return;
	}
	else
	{
		*pplist = phead->next;
	}
}

// 单链表查找
SListNode* SListFind(const SListNode** pplist, SLTDateType x)
{
	//SListNode* phead = *pplist;
	SListNode* ptail = *pplist;
	while (ptail)
	{
		if (ptail->data == x)
		{
			printf("已找到所求的数字:>\n");
			//phead->next = NULL;
			return ptail;
		}
		else 
		{
			ptail = ptail->next;
		}
	}
	printf("未找到所求的数字\n");
	return NULL;
}

// 在pos之前插入
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x)
{

	assert(pplist);
	assert(pos);
	SListNode* phead = *pplist;
	SListNode* ptail = *pplist;
	SListNode* pfront = phead->next;

	if (*pplist == pos)
	{
		if (*pplist == NULL)
		{
			SListNode* ptmp = BuySListNode(x);
			*pplist = ptmp;
		}
		else
		{
			SListNode* ptmp = BuySListNode(x);
			ptmp->next = phead;
			*pplist = ptmp;
		}
	}
	//else if (pos->next == NULL)
	//{
	//		while (pfront->next != NULL)
	//		{
	//			pfront = pfront->next;
	//			phead = phead->next;
	//		}
	//		SListNode* ptmp = BuySListNode(x);
	//		phead->next = ptmp;
	//		ptmp->next = pfront;
	//}
	else
	{
		while (ptail->next != pos)
		{
			ptail = ptail->next;
			phead = phead->next;
		}
		ptail = ptail->next;
		SListNode* ptmp = BuySListNode(x);
		phead->next = ptmp;
		ptmp->next = ptail;
	}
}



