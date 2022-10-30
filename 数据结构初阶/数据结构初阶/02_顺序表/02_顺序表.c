#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

//测试尾插
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

//测试尾删 
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

	SLPopBack(&sl);//size数值会小于0越界报错
	SLPrint(&sl);

	SLPushBack(&sl, 1);
	SLDestory(&sl);
}

//测试头插
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

//测试头删
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
	SLPopFront(&sl);//size数值会小于0越界报错

	SLPrint(&sl);
	
	SLDestory(&sl);
}

//测试查找
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

//测试查找后删除重复
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

//测试在pos位置进行插入
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

//测试在pos位置处删除
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


