#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef int HPDataType;

// ����ѵĽṹ��
typedef struct Heap
{
	HPDataType* _data;
	int _size;
	int _capacity;
}Heap;

// ���µ���
void AdjustDown_Big(HPDataType* data, int size, int parent);

void AdjustDown_Small(HPDataType* data, int size, int parent);

// ���ϵ���
void AdjustUp_Big(HPDataType* data, int child);

void AdjustUp_Small(HPDataType* data, int child);

// ������
void HeapSort_Down(int* a, int size);

void HeapSort_Up(int* a, int size);

// ��ʼ����
void HeapInit(Heap* php);

// �ѵĹ���
void HeapCreate(Heap* php, HPDataType* a, int n);

// �ѵ�����
void HeapDestroy(Heap* php);

// ��ӡ�ѵ�����
void HeapPrint(Heap* php);

// �ѵĲ���
void HeapPush_Small(Heap* php, HPDataType x);

void HeapPush_Big(Heap* php, HPDataType x);

// �ѵ�ɾ��
void HeapPop_Small(Heap* php);

void HeapPop_Big(Heap* php);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* php);

// �ѵ����ݸ���
int HeapSize(Heap* php);

// �ѵ��п�
bool HeapEmpty(Heap* php);

//��������ļ�����
void CreateFileData(int n, int k);


//// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
//// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
//// ��Ҫע�⣺
//// ������ǰK��������K������С��
//// ����С��ǰK��������K�����Ĵ��
//void PrintTopK(int* a, int n, int k);
//void TestTopk();


