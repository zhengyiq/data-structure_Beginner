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
	SListPrint_PP(&head);
}

//������������
void TestSList3()
{
	SListNode*head = CreateSList(10);
	SListPrint_PP(&head);
}

//����β��
void TestSList4()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode* head = NULL;//ok
	SListPushBack(&head, 10);
	SListPrint_PP(&head);
}

//����ͷ��
void TestSList5()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode* head = NULL;//ok
	SListPushFront(&head, 10);
	SListPrint_PP(&head);
}

//����βɾ
void TestSList6()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopBack(&head);
	SListPrint_PP(&head);
}

//����ͷɾ
void TestSList7()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopFront(&head);
	SListPrint_PP(&head);
}

//���Բ���
void TestSList8()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListNode* ret = SListFind_PP(&head, 0);
	SListPrint_PP(&ret);
}

//������pos֮ǰ����
void TestSList9()
{
	//�Ѿ������������ǰ����
	//SListNode*head2 = CreateSList(1);//ok
	SListNode*head = CreateSList(10);//ok
	SListNode* ret = SListFind_PP(&head, 10);
	//SListInsert(&head, head2, 10); 
	SListInsert(&head, ret, 10); 

	//δ��������
	//SListNode*head = NULL;
	//SListNode*head = CreateSList(1);//ok
	//SListInsert(&head, head, 10); 
	SListPrint_PP(&head);
}

//������pos�������
void TestSList10()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok

	SListNode* ret = SListFind_PP(&head, 9);
	SListInsertAfter(ret, 10);
	SListPrint_PP(&head);
}

//������pos�������
void TestSList11()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok

	SListNode* ret = SListFind_PP(&head, 0);
	SListErase(&head, ret);
	SListPrint_PP(&head);
}

//����ɾ��pos����λ��
void TestSList12()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok

	SListNode* ret = SListFind_PP(&head, 0);
	SListEraseAfter(ret);
	SListPrint_PP(&head);
}

int main()
{
	TestSList12();
	return 0;
}
