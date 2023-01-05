#include "Sort.h"
#include "Stack.h"

void TestInsertSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	InsertSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));

	//my_InsertSort(a, sizeof(a) / sizeof(int));
	//Print(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	SelectSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	HeapSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestPartSort1()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	Print(a, sizeof(a) / sizeof(int));
}

void TestQuickSortNonR()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	Print(a, sizeof(a) / sizeof(int));
}

void TestMergeSort()
{
	//int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	MergeSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestMergeSortNonR()
{
	//int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestContSort()
{
	//int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);

	int j = 0;
	for (int i = 0; i < N; ++i)
	{
		//a1[i] = rand();
		a1[i] = i;
		/*int x = rand();
		if (x % 7 == 0 && x % 3 == 0 && x % 2 == 0)
		{
		a1[i] = x;
		++j;
		}
		else
		{
		a1[i] = i;
		}*/

		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	//printf("%d\n", j);

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	int begin8 = clock();
	CountSort(a8, N);
	int end8 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end7 - begin7);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("CountSort:%d\n", end8 - begin8);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a8);
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestPartSort1();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	//TestContSort();
	TestOP();

	return 0;
}