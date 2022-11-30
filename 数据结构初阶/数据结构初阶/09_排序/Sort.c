#include "Sort.h"

void Swap(int* num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 向下调整，最后形成大堆
void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;

	while (child < n)
	{
		if ((a[child + 1] > a[child]) && (child + 1 < n))
		{
			child++;
		}

		if (a[child] > a[root])
		{
			//交换数据
			Swap(&a[child], &a[root]);
			//迭代祖孙
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


// 插入排序

//void my_InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = end + 1;
//		while (end >= 0)
//		{
//			if (a[end] > a[tmp])
//			{
//				Swap(&a[end], &a[tmp]);
//				end--;
//			}
//			else
//			{
//				break;
//			}
//			tmp = end + 1;
//		}
//	}
//}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int Maxi = begin;
	int Mini = begin;

	while (begin < end)
	{
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[Maxi] < a[i])
			{
				Maxi = i;
			}
			if (a[Mini] > a[i])
			{
				Mini = i;
			}
		}
 		Swap(&a[begin], &a[Mini]);
		if (Maxi == begin)
			Maxi = Mini;
		Swap(&a[end], &a[Maxi]);
		begin++;
		end--;
	}
}

// 堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end--, 0);
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j-1] > a[j])
			{
				Swap(&a[j-1], &a[j]);
			}
		}
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		while ((left < right) && (a[right] >= a[key]))
		{
			right--;
		}

		while ((left < right) && (a[left] <= a[key]))
		{
			left++;
		}
		
		Swap(&a[left], &a[right]);
	}

	Swap(&a[key], &a[left]);
	key = left;

	PartSort1(a, begin, key - 1);
	PartSort1(a, key + 1, end);
}