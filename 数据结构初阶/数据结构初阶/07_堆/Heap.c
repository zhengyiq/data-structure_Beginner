#include "Heap.h"

//初始化堆
void HeapInit(Heap* php)
{
	assert(php);

	php->_data = NULL;
	php->_size = 0;
	php->_capacity = 0;
}

// 堆的构建
void HeapCreate(Heap* php, HPDataType* a, int size)
{
	assert(php);

	//php->_capacity = size;
	HPDataType* newnode = (HPDataType*)realloc(php->_data, sizeof(HPDataType) * size);
	if (newnode == NULL)
	{
		perror("realloc failded");
		exit(-1);
	}
	php->_data = newnode;
	//php->_data = a;
	//php->_size = size;
	memcpy(php->_data, a, sizeof(HPDataType) * size);
	php->_data = a;
	php->_size = size;

	//建堆算法
	//向下调整建堆
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_Big(php->_data, php->_size, i);
	}

	//向上调整建堆
	for (int i = 1; i < size; i++)
	{
		AdjustUp_Big(php->_data, i);
	}

}

//交换函数
void Swap(HPDataType* num1, HPDataType* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//向上调整，最后形成大堆
void AdjustUp_Big(HPDataType* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//在这里由于是从下往上的不会有，没有有节点的影响
		if (data[child] > data[parent])
		{
			Swap(&data[child], &data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向上调整，最后形成小堆
void AdjustUp_Small(HPDataType* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//在这里由于是从下往上的不会有，没有有节点的影响
		if (data[child] < data[parent])
		{
			Swap(&data[child], &data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 堆的插入 - 大堆
void HeapPush_Big(Heap* php, HPDataType x)
{
	assert(php);

	//扩容
	if (php->_size == php->_capacity)
	{
		int newcapaticy = php->_capacity == 0 ? 4 : php->_capacity * 2;
		HPDataType* newnode = (HPDataType*)realloc(php->_data, sizeof(HPDataType) * newcapaticy);
		if (newnode == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}

		php->_data = newnode;
		php->_capacity = newcapaticy;
	}

	php->_data[php->_size] = x;
	php->_size++;

	AdjustUp_Big(php->_data, php->_size - 1);
}

// 堆的插入 - 小堆
void HeapPush_Small(Heap* php, HPDataType x)
{
	assert(php);

	//扩容
	if (php->_size == php->_capacity)
	{
		int newcapaticy = php->_capacity == 0 ? 4 : php->_capacity * 2;
		HPDataType* newnode = (HPDataType*)realloc(php->_data, sizeof(HPDataType) * newcapaticy);
		if (newnode == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}

		php->_data = newnode;
		php->_capacity = newcapaticy;
	}

	php->_data[php->_size] = x;
	php->_size++;

	AdjustUp_Small(php->_data, php->_size - 1);
}

// 向下调整，最后形成大堆
void AdjustDown_Big(HPDataType* data, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if ((data[child + 1] > data[child]) && (child + 1 < size))
		{
			child++;
		}

		if (data[child] > data[parent])
		{
			//交换数据
			Swap(&data[child], &data[parent]);
			//迭代祖孙
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 向下调整，最后形成小堆
void AdjustDown_Small(HPDataType* data, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if ((data[child + 1] < data[child]) && (child + 1 < size))
		{
			child++;
		}

		if (data[child] < data[parent])
		{
			//交换数据
			Swap(&data[child], &data[parent]);
			//迭代祖孙
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的删除 - 大堆
void HeapPop_Big(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_data[php->_size - 1], &php->_data[0]);
	php->_size--;

	AdjustDown_Big(php->_data, php->_size, 0);
}

// 堆的删除 - 小堆
void HeapPop_Small(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_data[php->_size - 1], &php->_data[0]);
	php->_size--;

	AdjustDown_Small(php->_data, php->_size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);


	return php->_data[0];
}

void HeapPrint(Heap* php)
{
	assert(php);
	assert(php->_size > 0);


	for (int i = 0; i < php->_size; i++)
	{
		printf("%d ", php->_data[i]);
	}
	printf("\n");
}

// 堆的销毁
void HeapDestroy(Heap* php)
{
	assert(php);

	free(php->_data);
	php->_data = NULL;

	php->_size = php->_capacity = 0;
}

// 堆的数据个数
int HeapSize(Heap* php)
{
	assert(php);

	return php->_size;
}

// 堆的判空
bool HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0;
}

// 升序的堆排序
void HeapSort_Up(int* a, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_Big(a, size, i);
	}
	HeapPrint(&a);

	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown_Big(a, end--, 0);
	}
	HeapPrint(&a);
}

// 降序的堆排序
void HeapSort_Down(int* a, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_Small(a, size, i);
	}
	HeapPrint(&a);

	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown_Small(a, end--, 0);
	}
	HeapPrint(&a);
}

// 创建随机数字的文件
void CreateFileData(int n, int k)
{
	FILE* fin = fopen("data.txt", "w");
	srand(time(0));
	if (fin == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}
	
	for (int i = 0; i < n; i++)
	{
		int val = rand()%10000;

		if ((val % 11 == 0) && k>0)
		{
			val = val + 100000;
			k--;
		}
		fprintf(fin, "%d\n", val);
	}

	fclose(fin);
}

// 测试从文件中读取数据TopK算法 - 最小的K个
void TestTopK_Min()
{
	int n = 0;
	int k = 0;

	printf("请输入n和k:>");
	scanf("%d%d", &n, &k);
	
	CreateFileData(n, k);

	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}

	HPDataType* a = (HPDataType*)malloc(sizeof(HPDataType) * k);
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &a[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_Big(a, k, i);
	}

	int val = 0;
	while ((fscanf(fout, "%d", &val)) != EOF)
	{
		if (val < a[0])
		{
			a[0] = val;
			AdjustDown_Big(a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", a[i]);
	}

	HeapSort_Up(a, k);

	fclose(fout);
}

// 测试从文件中读取数据TopK算法 - 最大的K个
void TestTopK_Max()
{
	int n = 0;
	int k = 0;

	printf("请输入n和k:>");
	scanf("%d%d", &n, &k);

	CreateFileData(n, k);

	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}

	HPDataType* a = (HPDataType*)malloc(sizeof(HPDataType) * k);
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &a[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_Small(a, k, i);
	}

	int val = 0;
	while ((fscanf(fout, "%d", &val)) != EOF)
	{
		if (val > a[0])
		{
			a[0] = val;
			AdjustDown_Small(a, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", a[i]);
	}

	HeapSort_Up(a, k);

	fclose(fout);
}