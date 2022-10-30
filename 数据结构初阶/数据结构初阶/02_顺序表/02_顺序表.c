#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//斐波那契额数列
//O（2^N）
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);
//}
//
////O（N）
//long long Fib_(size_t N)
//{
//	int num1 = 1;
//	int num2 = 1;
//	int num3 = 1;
//	int ret = 1;
//	if (N < 3)
//		return 1;
//	for (int  i = 2; i < N; i++)
//	{
//		num3 = num1 + num2;
//		ret = num3;
//		num1 = num2;
//		num2 = num3;
//	}
//	return ret;
//}
//
//int main()
//{
//	//printf("%lld\n", Fib(30));
//	printf("%lld\n", Fib_(7));
//	return 0;
//}
//
//#include <stdio.h>
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//	return Fac(N - 1) * N;
//}
//
//int main(void)
//{
//	printf("%lld\n", Fac(10000)); 
//	return 0;
//}


//#include <stdio.h>
//
//void func1()
//{
//	int a = 0;
//	printf("%p\n", &a);	//00B6F9D4
//}
//void func2()
//{
//	int b = 0;
//	printf("%p\n", &b); //00B6F9D4
//}
//int main(void)
//{
//	func1();
//	func2();
//	return 0;
//}


//旋转数组
//	 k = k % numsSize;
//	 // 变长数组
//	 int tmp[numsSize];
//	
//	 // 后k个拷贝到前面
//	 int j = 0;
//	 for(int i = numsSize-k; i < numsSize; ++i)
//	 {
//	     tmp[j] = nums[i];
//	     ++j;
//	 }
//	
//	 //前n-k个拷贝到后面
//	 for(int i = 0; i < numsSize-k; ++i)
//	 { 
//	     tmp[j] = nums[i];
//	     ++j;
//	 }
//	     for(int i = 0; i < numsSize; ++i)
//	 {
//	     nums[i] = tmp[i];//将数组拷贝回原数组
//	 }

//void reservse(int*a, int begin, int end)
//{
//	while (begin < end)
//	{
//		int tmp = a[begin];
//		a[begin] = a[end];
//		a[end] = tmp;
//
//		++begin;
//		--end;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	k = k % numsSize;
//
//	reservse(nums, 0, numsSize - k - 1);
//	reservse(nums, numsSize - k, numsSize - 1);
//	reservse(nums, 0, numsSize - 1);

//}
//数据结构初阶——斐波那契额数列的复杂度和顺序表

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
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	//SLPrint(&sl);
	int ret = SLFind(&sl, 2);
	printf("%d", sl.a[ret]);

	SLDestory(&sl);
}

//测试在pos位置进行插入
void TestSeqList6()
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
	SLErase(&sl, 4);
	SLPrint(&sl);
	SLDestory(&sl);
}


int main(void)
{
	TestSeqList7();
	return 0;
}


