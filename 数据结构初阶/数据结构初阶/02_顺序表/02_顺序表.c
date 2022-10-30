#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

//����β��
void TestSeqList1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	SLDestory(&sl);
}

//����βɾ 
void TestSeqList2()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);

	SLPopBack(&sl);//size��ֵ��С��0Խ�籨��
	SLPrint(&sl);

	SLPushBack(&sl, 1);
	SLDestory(&sl);
}

//����ͷ��
void TestSeqList3()
{
	SL sl;
	SLInit(&sl);
	//SLPushBack(&sl, 1);
	//SLPushBack(&sl, 2);
	//SLPushBack(&sl, 3);
	//SLPushBack(&sl, 4);
	//SLPushBack(&sl, 5);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPrint(&sl);
	SLDestory(&sl);
}

//����ͷɾ
void TestSeqList4()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);//size��ֵ��С��0Խ�籨��

	SLPrint(&sl);
	
	SLDestory(&sl);
}

//���Բ���
void TestSeqList5()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 2);
	//SLPrint(&sl);
	int ret = SLFind_Single(&sl, 2);
	printf("%d", sl.a[ret]);

	SLDestory(&sl);
}

//���Բ��Һ�ɾ���ظ�
void TestSeqList6()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 1);
	int ret = SLFind_double(&sl, 2, 0);
	while (ret != -1)
	{
		SLErase(&sl, ret);
		ret = SLFind_double(&sl, 2, ret);
	}
	SLPrint(&sl);



	SLDestory(&sl);
}

//������posλ�ý��в���
void TestSeqList7()
{
	SL sl;
	SLInit(&sl);

	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);
	SLInsert(&sl, 2, 10);
	SLPrint(&sl);
	SLDestory(&sl);
}

//������posλ�ô�ɾ��
void TestSeqList8()
{
	SL sl;
	SLInit(&sl);

	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);
	SLErase(&sl, 4);
	SLPrint(&sl);
	SLDestory(&sl);
}


int main(void)
{
	TestSeqList7();
	return 0;
}


