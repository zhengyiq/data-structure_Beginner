#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
typedef int HPDataType;

// 定义堆的结构体
typedef struct Heap
{
	HPDataType* _data;
	int _size;
	int _capacity;
}Heap;

// 向下调整
void AdjustDown_Big(HPDataType* data, int size, int parent);

void AdjustDown_Small(HPDataType* data, int size, int parent);

// 向上调整
void AdjustUp_Big(HPDataType* data, int child);

void AdjustUp_Small(HPDataType* data, int child);

// 堆排序
void HeapSort_Down(int* a, int size);

void HeapSort_Up(int* a, int size);

// 初始化堆
void HeapInit(Heap* php);

// 堆的构建
void HeapCreate(Heap* php, HPDataType* a, int n);

// 堆的销毁
void HeapDestroy(Heap* php);

// 打印堆的数据
void HeapPrint(Heap* php);

// 堆的插入
void HeapPush_Small(Heap* php, HPDataType x);

void HeapPush_Big(Heap* php, HPDataType x);

// 堆的删除
void HeapPop_Small(Heap* php);

void HeapPop_Big(Heap* php);

// 取堆顶的数据
HPDataType HeapTop(Heap* php);

// 堆的数据个数
int HeapSize(Heap* php);

// 堆的判空
bool HeapEmpty(Heap* php);

//创建随机文件数据
void CreateFileData(int n, int k);


//// TopK问题：找出N个数里面最大/最小的前K个问题。
//// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
//// 需要注意：
//// 找最大的前K个，建立K个数的小堆
//// 找最小的前K个，建立K个数的大堆
//void PrintTopK(int* a, int n, int k);
//void TestTopk();


