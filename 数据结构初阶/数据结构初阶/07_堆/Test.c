#include "Heap.h"

void TestHeap1()
{
	//int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int array[] = { 10, 15, 19, 25, 18, 34, 65, 49, 27, 37, 28 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	HeapInit(&hp);

	for (int  i = 0; i < sz; i++)
	{
		HeapPush_Small(&hp, array[i]);
	}
	//HeapPush_Small(&hp, 5);
	HeapPop_Small(&hp);

	HeapPrint(&hp);

	printf("\n");

	//HeapPrint(&hp);

}

void TestHeap2()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };

	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		HeapPush_Small(&hp, array[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop_Big(&hp);
	}

	HeapDestroy(&hp);
}

void TestHeap3()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	//HeapInit(&hp);
	//HeapCreate(&hp, array, sz);
	//HeapPrint(&hp);
	HeapSort_Up(array, sz);
}

void TestHeap4()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	HeapInit(&hp);

	for (int i = 0; i < sz; i++)
	{
		HeapPush_Small(&hp, array[i]);
	}

	printf("%d ", HeapTop(&hp));

	printf("\n");

	printf("%d ", HeapEmpty(&hp));

	printf("\n");
	
	printf("%d ", HeapSize(&hp));

}


int main()
{
	//CreateFileData();
	TestHeap1();
	TestTopK_Min();
	return 0;
}