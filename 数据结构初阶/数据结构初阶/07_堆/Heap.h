#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef int HPDataType;

//����ѵĽṹ��
typedef struct Heap
{
	HPDataType* _data;
	int _size;
	int _capacity;
}Heap;

//��ʼ����
void HeapInit(Heap* php);

// �ѵĹ���
void HeapCreate(Heap* php, HPDataType* a, int n);

// �ѵ�����
void HeapDestroy(Heap* php);

//��ӡ�ѵ�����
void HeapPrint(Heap* php);

// �ѵĲ���
void HeapPush(Heap* php, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* php);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* php);

// �ѵ����ݸ���
int HeapSize(Heap* php);

// �ѵ��п�
bool HeapEmpty(Heap* php);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();

void HeapSort(int *a, int size);

void CreateFileData();

