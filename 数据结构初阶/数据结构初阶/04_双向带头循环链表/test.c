#include "List.h"

//≤‚ ‘¡¥±Ì≥ı ºªØ
void TestListNode1()
{
	ListNode* head = ListNodeInit();
}

//≤‚ ‘¡¥±ÌŒ≤≤Â°¢Œ≤…æ
void TestListNode2()
{
	ListNode* head = ListNodeInit();
	ListNodePushBack(head, 1);
	ListNodePrint(head);
	ListNodePushBack(head, 2);
	ListNodePrint(head);
	ListNodePushBack(head, 3);
	ListNodePrint(head);
	ListNodePushBack(head, 4);
	ListNodePrint(head);
	ListNodePushBack(head, 5);
	ListNodePrint(head);
	ListNodePopBack(head);
	ListNodePrint(head);
	ListNodePopBack(head);
	ListNodePrint(head);
	ListNodePopBack(head);
	ListNodePrint(head);
	ListNodePopBack(head);
	ListNodePrint(head);
	ListNodePopBack(head);
	ListNodePrint(head);

}

//≤‚ ‘¡¥±ÌÕ∑≤Â°¢Õ∑…æ
void TestListNode3()
{
	ListNode* head = ListNodeInit();
	ListNodePushFront(head, 1);
	ListNodePrint(head);
	ListNodePushFront(head, 2);
	ListNodePrint(head);
	ListNodePushFront(head, 3);
	ListNodePrint(head);
	ListNodePushFront(head, 4);
	ListNodePrint(head);
	ListNodePushFront(head, 5);
	ListNodePrint(head);
	ListNodePopFront(head);
	ListNodePrint(head);
	ListNodePopFront(head);
	ListNodePrint(head);
	ListNodePopFront(head);
	ListNodePrint(head);
	ListNodePopFront(head);
	ListNodePrint(head);
	ListNodePopFront(head);
	ListNodePrint(head);

}

//≤‚ ‘≤È’“
void TestListNode4()
{
	ListNode* head = ListNodeInit();
	ListNodePushFront(head, 1);
	ListNodePushFront(head, 2);
	ListNodePushFront(head, 3);
	ListNodePushFront(head, 4);
	ListNodePushFront(head, 5);
	ListNodePrint(head);

	ListNode* ret = ListNodeFind(head, 5);
	ListNodePrint(ret);
}
int main(void)
{
	TestListNode2();
	return 0;
}