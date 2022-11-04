#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//��������ڵ�
void TestSList1()
{
	//SListNode* n1 = malloc();
	//SListNode* n2 = malloc();
	//n2->next = n1;
	//��Щ�����Ǵ�����ջ֡��ĵľֲ��������ں���������ʱ��ͻ����٣���������ݾͻ���ʧ

	SListNode* head = BuySListNode(1);
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
	SListPrint(head);
}

//����βɾ
void TestSList6()
{
	//SListNode*head = CreateSList(10);//ok
	SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopBack(&head);
	SListPrint(head);
}

//����ͷɾ
void TestSList7()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListPopFront(&head);
	SListPrint(head);
}

//���Բ���
void TestSList8()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok
	SListNode* ret = SListFind(head, 0);
	SListPrint(ret);
}

//������pos֮ǰ����
void TestSList9()
{
	//�Ѿ������������ǰ����
	//SListNode*head2 = CreateSList(1);//ok
	SListNode*head = CreateSList(10);//ok
	SListNode* ret = SListFind(head, 0);
	//SListInsert(&head, head2, 10); 
	SListInsert(&head, ret, 10); 

	//δ��������
	//SListNode*head = NULL;
	//SListNode*head = CreateSList(1);//ok
	//SListInsert(&head, head, 10); 
	SListPrint(head);
}

//������pos�������
void TestSList10()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok

	SListNode* ret = SListFind(head, 9);
	SListInsertAfter(ret, 10);
	SListPrint(head);
}

//������posɾ��
void TestSList11()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok

	SListNode* ret = SListFind(head, 0);
	SListErase(&head, ret);
	SListPrint(head);
}

//����ɾ��pos����λ��
void TestSList12()
{
	SListNode*head = CreateSList(10);//ok
	//SListNode*head = CreateSList(1);//ok
	//SListNode* head = NULL;//ok

	SListNode* ret = SListFind(head, 0);
	SListEraseAfter(ret);
	SListPrint(head);
}

int main()
{
	TestSList11();
	return 0;
}
