#include "Sort.h"
#include "Stack.h"

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

// ���µ���������γɴ��
void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;

	while (child < n)
	{
		if ((child + 1 < n) && (a[child + 1] > a[child]))
		{
			child++;
		}

		if (a[child] > a[root])
		{
			//��������
			Swap(&a[child], &a[root]);
			//��������
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


// ��������

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

// ϣ������
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

// ѡ������
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

// ������
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

// ð������
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

//����ȡ��
int FindMidNum(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] > a[mid])
	{
		if (a[end] > a[begin])
		{
			return begin;
		}
		else if (a[end] < a[mid])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
	if (a[begin] < a[mid])
	{
		if (a[end] < a[begin])
		{
			return begin;
		}
		else if (a[end] > a[mid])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
}

// ��������hoare�汾
int PartSort1(int* a, int begin, int end)
{
	int mid = FindMidNum(a, begin, end);
	Swap(&a[mid], &a[begin]);
	/*int keyi = begin;*/

	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		while ((left < right) && (a[right] >= a[keyi]))
		{
			right--;
		}

		while ((left < right) && (a[left] <= a[keyi]))
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

// �ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int mid = FindMidNum(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int left = begin;
	int right = end;
	int hole = begin;
	int key = a[begin];

	while (left < right)
	{
		//�ұ���С�����ߵĿ���
		while (left < right && a[right] > key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;

		//����Ҵ���ұߵĿ���
		while (left < right && a[left] < key)
		{
			++left;
		}
		Swap(&a[hole], &a[left]);
		hole = left;
	}
	a[hole] = key;
	return hole;
}

// ˫ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int mid = FindMidNum(a, begin, end);
	Swap(&a[mid], &a[begin]);
	
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	while (cur <= end)
	{
		//�ҵ���kС��ֵ��++prev���н�����С����ǰ�����������
		//if (a[cur] < a[keyi] && ++prev != cur)
		//	Swap(&a[prev], &a[cur]);

		if (a[cur] < a[keyi])
		{
			Swap(&a[++prev], &a[cur]);
		}
		++cur;
	}

	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin + 1) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}

	else
	{
		int keyi = PartSort2(a, begin, end);

		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}

// ���ŷǵݹ�
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyi = PartSort3(a, left, right);
		
		if (keyi - 1 > left)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

		if (right > keyi + 1)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}
// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	
	// ȥ�м��ֵ���зָ�
	int mid = (begin + end) / 2;

	// �����ڶ������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// ʹ��begin1��begin2����¼�����������ʼλ��
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//������õ����鿽����ԭ����
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}


// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	int rangeN = 1;
	while (rangeN < n)
	{
		for (int j = 0; j < n; j += rangeN * 2)
		{
			int begin1 = j, end1 = j + rangeN - 1;
			int begin2 = j + rangeN, end2 = j + 2 * rangeN - 1;
			int i = j;

			//��Ҫ��Խ�����������ж�
			//���������Խ��ķ���
			//1������
			//2������
			//����ʹ��end1 = begin2 = end2 = n-1 �������������ᵼ���������
			if (end1 >= n)
			{
				end1 = n - 1;
				begin2 = n; 
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[i++] = a[begin1++];
				}
				else
				{
					tmp[i++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[i++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[i++] = a[begin2++];
			}

			//������õ����鿽����ԭ����
			memcpy(a + j, tmp + j, sizeof(int) * (end2 - j + 1));
		}
			//������õ����鿽����ԭ����
			//����ʹ��break�ķ�ʽ��Ҫ������������С�
			//memcpy(a, tmp, sizeof(int) * (n));
			rangeN *= 2;
	}

	free(tmp);
	tmp = NULL;
}


//���������Ż�
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + rand() % (end - begin);
	if (a[begin] > a[mid])
	{
		if (a[end] > a[begin])
		{
			return begin;
		}
		else if (a[end] < a[mid])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
	if (a[begin] < a[mid])
	{
		if (a[end] < a[begin])
		{
			return begin;
		}
		else if (a[end] > a[mid])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
}
void QuickSort_(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin) < 15)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int mid = GetMidIndex(a, begin, end);
		Swap(&a[mid], &a[begin]);

		int left = begin;
		int right = end;
		int key = a[begin];
		int cur = begin + 1;

		while (cur <= right)
		{
			if (a[cur] < key)
			{
				Swap(&a[cur], &a[left]);
				cur++;
				left++;
			}
			else if (a[cur] > key)
			{
				Swap(&a[cur], &a[right]);
				--right;
			}
			else
			{
				cur++;
			}
		}
		QuickSort_(a, begin, left - 1);
		QuickSort_(a, right + 1, end);
	}
}

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	
	int range = max - min + 1;
	int* countA = (int*)calloc(range, sizeof(int));
	if (countA == NULL)
	{
		perror("calloc failed");
	}

	// ͳ�ƴ���
	for (int i = 0; i < range; i++)
	{
		countA[a[i] - min]++;
	}
	
	// ����
	int k = 0;
	for (int j = 0; j < range; j++)
	{
		while (countA[j]--)
		{
			a[k++] = j + min;
		}
	}
	free(countA);
}
