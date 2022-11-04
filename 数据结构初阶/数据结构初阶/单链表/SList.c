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
void SListPrint_PP(const SListNode** pplist)
{
	assert(pplist);
	while (*pplist != NULL)
	{
		printf("%d ", (*pplist)->data);
		*pplist = (*pplist)->next;
	}
	//printf("NULL");
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		//printf("[%d|%p]->", cur->data, cur->next);
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
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

//void SListPushBack(SListNode* plist, SLTDateType x)
//{
//	SListNode* phead = plist;
//	SListNode* ptmp = BuySListNode(x);
//	if (plist == NULL)
//	{
//		plist = ptmp;
//	}
//	else
//	{
//		while (phead->next != NULL)
//		{
//			phead = phead->next;
//		}
//		phead->next = ptmp;
//	}
//}

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
		SListNode* newnode = BuySListNode(x);
		newnode->next = phead;
		*pplist = newnode;
//	}
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	SListNode* prev = *pplist;
	SListNode* ptail = prev->next;
	if (prev->next == NULL)
	{
		free(prev);
		*pplist = NULL;
		return;
	}
	while (ptail->next != NULL)
	{
		ptail = ptail->next;
		prev = prev->next;
	}
	free(prev->next);
	prev->next = NULL;
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode* next =(*pplist)->next;
	free(*pplist);
	*pplist = next;
}
//void SListPopFront(SListNode** pplist)
//{
//	assert(*pplist);
//	SListNode* phead = *pplist;
//	if (phead == NULL)
//	{
//		free(phead);
//		*pplist = NULL;
//		return;
//	}
//	else
//	{
//		*pplist = phead->next;
//		free(phead);
//		phead = NULL;
//	}
//}

// 单链表查找

//SListNode* SListFind_PP(const SListNode** pplist, SLTDateType x)
//{
//	//SListNode* phead = *pplist;
//	SListNode* ptail = *pplist;
//	while (ptail)
//	{
//		if (ptail->data == x)
//		{
//			printf("已找到所求的数字:>%d\n", ptail->data);
//			//phead->next = NULL;
//			return ptail;
//		}
//		else 
//		{
//			ptail = ptail->next;
//		}
//	}
//	printf("未找到所求的数字\n");
//	return NULL;
//}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}


// 在pos之前插入
void SListInsert(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	assert(pplist);
	assert(pos);
	SListNode* phead = *pplist;
	SListNode* ptail = *pplist;
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
	else
	{
		while (ptail->next != pos)
		{
			ptail = ptail->next;
			assert(ptail);
		} 
		SListNode* ptmp = BuySListNode(x);
		ptail->next = ptmp;
		ptmp->next = pos;
	}
}

// 在pos后面插入
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* phead = pos;
	SListNode* ptmp = BuySListNode(x);
	ptmp->next = phead->next;
	phead->next = ptmp;
}
 
// 删除pos位置
void SListErase(SListNode** pplist, SListNode* pos)
{
	assert(pos);
	assert(*pplist);
	if (*pplist == pos) 
	{
		SListPopFront(pplist);
	}
	else
	{
		SListNode* phead = *pplist;
		while (phead->next != pos)
		{
			phead = phead->next;
			// 检查pos不是链表中节点，参数传错了
			assert(phead);
		}
		phead->next = pos->next;
		free(pos);
	}
}

// 删除pos后面位置
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
		return;
	else
	{
		SListNode* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}

void SListDestroy(SListNode** pplist)
{
	assert(pplist);
	SListNode* phead = *pplist;
	while (phead != NULL)
	{
		SListNode* next = phead->next;
		free(phead);
		phead = next;
	}
	*pplist = NULL;
}
