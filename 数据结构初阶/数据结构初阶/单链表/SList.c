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

// �������ӡ
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
// �������ӡ
void SListPrint(SListNode* pplist)
{
	SListNode* phead = pplist;
	while (phead != NULL)
	{
		//printf("[%d|%p]->", cur->data, cur->next);
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

//����һ������
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

// ������β��
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

// �������ͷ��
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

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
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
	free(phead->next);
	phead->next = NULL;
}

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
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
		free(phead);
		phead = NULL;
	}
}

// ���������
SListNode* SListFind_PP(const SListNode** pplist, SLTDateType x)
{
	//SListNode* phead = *pplist;
	SListNode* ptail = *pplist;
	while (ptail)
	{
		if (ptail->data == x)
		{
			printf("���ҵ����������:>%d\n", ptail->data);
			//phead->next = NULL;
			return ptail;
		}
		else 
		{
			ptail = ptail->next;
		}
	}
	printf("δ�ҵ����������\n");
	return NULL;
}

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



// ��pos֮ǰ����
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
	else
	{
		while (ptail->next != pos)
		{
			ptail = ptail->next;
			//phead = phead->next;
			assert(ptail);
		}
		//ptail = ptail->next;
		SListNode* ptmp = BuySListNode(x);
		//phead->next = ptmp;
		ptail->next = ptmp;
		ptmp->next = pos;
	}
}

// ��pos�������
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* phead = pos;
	SListNode* ptmp = BuySListNode(x);
	ptmp->next = phead->next;
	phead->next = ptmp;
}

// ɾ��posλ��
void SListErase(SListNode** pplist, SListNode* pos)
{
	assert(pplist);
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

			// ���pos���������нڵ㣬����������
			assert(phead);
		}

		phead->next = pos->next;
		free(pos);
		//pos = NULL;
	}
}

// ɾ��pos����λ��
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
