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

// ������ͷɾ
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

// ���������
SListNode* SListFind(const SListNode** pplist, SLTDateType x)
{
	//SListNode* phead = *pplist;
	SListNode* ptail = *pplist;
	while (ptail)
	{
		if (ptail->data == x)
		{
			printf("���ҵ����������:>\n");
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



