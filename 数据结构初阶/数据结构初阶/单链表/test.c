#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//��������ڵ�
void TestSList1()
{
	SListNode*head = BuySListNode(1);
}

//���Դ�ӡ
void TestSList2()
{
	SListNode*head = BuySListNode(1);
	SListPrint(&head);
}

//������������
void TestSList3()
{
	SListNode*head = CreateSList(10);
	SListPrint(&head);
}

//����β��
void TestSList4()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode* head = NULL;//ok
	SListPushBack(&head, 10);
	SListPrint(&head);
}

//����ͷ��
void TestSList5()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode* head = NULL;//ok
	SListPushFront(&head, 10);
	SListPrint(&head);
}

//����βɾ
void TestSList6()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopBack(&head);
	SListPrint(&head);
}

//����ͷɾ
void TestSList7()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopFront(&head);
	SListPrint(&head);
}

//���Բ���
void TestSList8()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListNode* ret = SListFind(&head, 0);
	SListPrint(&ret);
}

//������pos֮ǰ����
void TestSList9()
{
	//�Ѿ������������ǰ����
	SListNode*head2 = CreateSList(1);//ok

	SListNode*head = CreateSList(10);//ok
	SListNode* ret = SListFind(&head, 0);
	//SListInsert(&head, head2, 10); 

	//δ��������
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
