#include "Heap.h"

void AdjustDown(HPDataType* data, int size, int parent);
void AdjustUp(HPDataType* data, int child);
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
		AdjustDown(php->_data, php->_size, i);
	}

	//���ϵ�������
	for (int i = 1; i < size; i++)
	{
		AdjustUp(php->_data, i);
	}

}

void Swap(HPDataType* num1, HPDataType* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void AdjustUp(HPDataType* data, int child)
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

// �ѵĲ���
void HeapPush(Heap* php, HPDataType x)
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

	AdjustUp(php->_data, php->_size - 1);
}

void AdjustDown(HPDataType* data, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if ((data[child + 1] < data[child]) && (child + 1 < size))
		{
			child++;
		}

		if (data[child] > data[parent])
		{
			break;
		}
		else
		{
			//��������
			Swap(&data[child], &data[parent]);
			//��������
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

// �ѵ�ɾ��
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_data[php->_size - 1], &php->_data[0]);
	php->_size--;

	AdjustDown(php->_data, php->_size, 0);
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

//����Ķ�����
void HeapSort(int* a, int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}
	HeapPrint(&a);

	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end--, 0);
	}
	HeapPrint(&a);
}


void CreateFileData()
{
	int k = 5;
	FILE* fin = fopen("data.txt", "w");
	srand(time(0));
	if (fin == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}
	
	for (int i = 0; i < 100; i++)
	{
		int val = rand()%10000;

		if ((val % 3 == 0) && k>0)
		{
			val = val + 100000;
			k--;
		}
		fprintf(fin, "%d\n", val);


	}

	fclose(fin);
}

void TestTopK()
{
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen failed");
		exit(-1);
	}

	HPDataType* a = (HPDataType*)malloc(sizeof(HPDataType) * 5);
	for (int i = 0; i < 5; i++)
	{
		fscanf(fout, "%d", &a[i]);
	}

	for (int i = (5 - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, 5, i);
	}
	int val = 0;
	while ((fscanf(fout, "%d", &val)) != EOF)
	{
		if (val > a[0])
		{
			a[0] = val;
			AdjustDown(a, 5, 0);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}

	HeapSort(a, 5);

	fclose(fout);
}