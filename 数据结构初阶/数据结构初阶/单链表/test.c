#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//测试申请节点
void TestSList1()
{
	SListNode*head = BuySListNode(1);
}

//测试打印
void TestSList2()
{
	SListNode*head = BuySListNode(1);
	SListPrint(&head);
}

//测试生成链表
void TestSList3()
{
	SListNode*head = CreateSList(10);
	SListPrint(&head);
}

//测试尾插
void TestSList4()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode* head = NULL;//ok
	SListPushBack(&head, 10);
	SListPrint(&head);
}

//测试头插
void TestSList5()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode* head = NULL;//ok
	SListPushFront(&head, 10);
	SListPrint(&head);
}

//测试尾删
void TestSList6()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopBack(&head);
	SListPrint(&head);
}

//测试头删
void TestSList7()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopFront(&head);
	SListPrint(&head);
}

//测试查找
void TestSList8()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListNode* ret = SListFind(&head, 0);
	SListPrint(&ret);
}

//测试在pos之前插入
void TestSList9()
{
	//已经产生链表后往前插入
	SListNode*head2 = CreateSList(1);//ok

	SListNode*head = CreateSList(10);//ok
	SListNode* ret = SListFind(&head, 0);
	//SListInsert(&head, head2, 10); 

	//未产生链表
	//SListNode*head = NULL;
	//SListNode*head = CreateSList(1);//ok
	//SListInsert(&head, head, 10); 
	SListPrint(&head);
}
int main()
{
	TestSList9();
	return 0;
}
