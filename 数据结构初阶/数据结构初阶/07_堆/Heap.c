

#include "Heap.h"

//��ʼ����
void HeapInit(Heap* php)
{
	assert(php);

	php->_data = NULL;
	php->_size = 0;
	php->_capacity = 0;
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
		if ((data[child + 1] > data[child]) && (child + 1 < size))
		{
			child++;
		}

		if (data[child] < data[parent])
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
//void HeapDestory(Heap* php)
//{
//	assert(php);
//
//	free(php->_data);
//	php->_data = NULL;
//
//	php->_size = php->_capacity = 0;
//}
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