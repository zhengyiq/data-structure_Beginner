#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

ListNode* ListNodeInit()
{
	//创建带哨兵位的头结点
	ListNode* guard = BuyListNode(-1);

	//令哨兵位的prev指针与next指针都指向结点本身 - 
	guard->next = guard;
	guard->prev = guard;
	return guard;
}

void ListNodePrint(ListNode* head)
{
	assert(head);
	ListNode* cur = head;
	while (cur->next != head)
	{
		printf("%d ", cur->next->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListNodePushBack(ListNode* head, LTDataType x)
{
	//assert(head);
	//ListNode* tail = head->prev;
	//ListNode* newnode = BuyListNode(x);
	//tail->next = newnode;
	//newnode->prev = tail;
	//head->prev = newnode;
	//newnode->next = head;

	ListNodeInsert(head, x);

}

void ListNodePopBack(ListNode* head)
{
	//assert(head);
	//assert(head != head->next);
	//ListNode* n_tail = head->prev->prev;
	//free(n_tail->next);
	//n_tail->next = head;
	//head->prev = n_tail;

	//assert(head);
	//assert(head != head->next);
	//ListNode* tail = head->prev;
	//ListNode* tailPrev = tail->prev;
	//tailPrev->next = head;
	//head->prev = tailPrev;
	//free(tail);

	ListNodeErase(head->prev);

}

void ListNodePushFront(ListNode* head, LTDataType x)
{
	//ListNode* newnode = BuyListNode(x);
	//newnode->next = head->next;
	//head->next->prev = newnode;
	//head->next = newnode;
	//newnode->prev = head;

	ListNodeInsert(head->next, x);
}

void ListNodePopFront(ListNode* head)
{
	//assert(head);
	//assert(head != head->next);
	//ListNode* next = head->next->next;
	//free(head->next);
	//head->next = next;
	//next->prev = head;

	//assert(head);
	//assert(head != head->next);
	//ListNode* first = head->next;
	//ListNode* second = first->next;
	//free(first);
	//head->next = second;
	//second->prev = head;

	ListNodeErase(head->next);

}

ListNode* ListNodeFind(ListNode* head, LTDataType x)
{
	//assert(head);
	//ListNode* cur = head;
	//while (cur->next != head)
	//{
	//	if (cur->next->data == x)
	//	{ 
	//		return cur->next;
	//		printf("已找到");
	//	}
	//	cur = cur->next;
	//}
	//printf("未找到");
	//return NULL;

	assert(head);
	ListNode* cur = head->next;
	while (cur != head)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

void ListNodeInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* Prev = pos->prev;
	Prev->next = newnode;
	newnode->prev = Prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListNodeErase(ListNode* pos)
{
	assert(pos);
	ListNode* Prev = pos->prev;
	ListNode* Next = pos->next;
	Prev->next = Next;
	Next->prev = Prev;
}

bool ListNodeEmpty(ListNode* head)
{
	return head == head->next;
}

size_t ListNodeSize(ListNode* head)
{
	assert(head);

	size_t size = 0;
	ListNode* cur = head->next;
	while (cur != head)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

void ListNodeDestroy(ListNode* head)
{
	assert(head);

	ListNode* cur = head->next;
	while (cur != head)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	//phead = NULL;
}