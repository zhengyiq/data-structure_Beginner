#include "Heap.h"

//��ʼ����
void HeapInit(Heap* php)
{
	assert(php);

	php->_data = NULL;
	php->_size = 0;
	php->_capacity = 0;
}

// �ѵĹ���
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

	//�����㷨
	//���µ�������
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_Big(php->_data, php->_size, i);
	}

	//���ϵ�������
	for (int i = 1; i < size; i++)
	{
		AdjustUp_Big(php->_data, i);
	}

}

//��������
void Swap(HPDataType* num1, HPDataType* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//���ϵ���������γɴ��
void AdjustUp_Big(HPDataType* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//�����������Ǵ������ϵĲ����У�û���нڵ��Ӱ��
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

//���ϵ���������γ�С��
void AdjustUp_Small(HPDataType* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		//�����������Ǵ������ϵĲ����У�û���нڵ��Ӱ��
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

// �ѵĲ��� - ���
void HeapPush_Big(Heap* php, HPDataType x)
{
	assert(php);

	//����
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

// �ѵĲ��� - С��
void HeapPush_Small(Heap* php, HPDataType x)
{
	assert(php);

	//����
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

// ���µ���������γɴ��
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
			//��������
			Swap(&data[child], &data[parent]);
			//��������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// ���µ���������γ�С��
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
			//��������
			Swap(&data[child], &data[parent]);
			//��������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// �ѵ�ɾ�� - ���
void HeapPop_Big(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_data[php->_size - 1], &php->_data[0]);
	php->_size--;

	AdjustDown_Big(php->_data, php->_size, 0);
}

// �ѵ�ɾ�� - С��
void HeapPop_Small(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_data[php->_size - 1], &php->_data[0]);
	php->_size--;

	AdjustDown_Small(php->_data, php->_size, 0);
}

// ȡ�Ѷ�������
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

// �ѵ�����
void HeapDestroy(Heap* php)
{
	assert(php);

	free(php->_data);
	php->_data = NULL;

	php->_size = php->_capacity = 0;
}

// �ѵ����ݸ���
int HeapSize(Heap* php)
{
	assert(php);

	return php->_size;
}

// �ѵ��п�
bool HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0;
}

// ����Ķ�����
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

// ����Ķ�����
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

// ����������ֵ��ļ�
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

// ���Դ��ļ��ж�ȡ����TopK�㷨 - ��С��K��
void TestTopK_Min()
{
	int n = 0;
	int k = 0;

	printf("������n��k:>");
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

// ���Դ��ļ��ж�ȡ����TopK�㷨 - ����K��
void TestTopK_Max()
{
	int n = 0;
	int k = 0;

	printf("������n��k:>");
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