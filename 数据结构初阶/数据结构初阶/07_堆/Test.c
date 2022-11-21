#include "Heap.h"

void TestHeap1()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	HeapInit(&hp);

	for (int  i = 0; i < sz; i++)
	{
		HeapPush(&hp, array[i]);
	}

	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);

	printf("%d ", HeapEmpty(&hp));

	printf("\n");

	HeapPrint(&hp);

}

void TestHeap3()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		HeapPush(&hp, array[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

void TestHeap4()
{
	int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	//HeapInit(&hp);
	//HeapCreate(&hp, array, sz);
	//HeapPrint(&hp);
	HeapSort(array, sz);
}

void TestHeap5()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heap hp;
	HeapInit(&hp);

	for (int i = 0; i < sz; i++)
	{
		HeapPush(&hp, array[i]);
	}

	printf("%d ", HeapTop(&hp));

	printf("\n");

	printf("%d ", HeapEmpty(&hp));

	printf("\n");
	
	printf("%d ", HeapSize(&hp));

}


int main()
{
	//TestHeap4();
	//CreateFileData();
	TestTopK();

}