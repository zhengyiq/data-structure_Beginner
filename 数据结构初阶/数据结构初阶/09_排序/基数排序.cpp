//#include <iostream>
//#include <queue>
//using namespace std;
//
//#define K 3
//#define RADIX 10
//
////定义基数
//queue<int> Q[RADIX];
//
//int GetKey(int value, int k)
//{
//	int key = 0;
//	while (k >= 0)
//	{
//		key = value % 10;
//		value /= 10;
//		k--;
//	}
//	return key;
//}
//
//void Distribute(int arr[], int left, int right, int k)
//{
//	for (int i = left; i < right; i++)
//	{
//		int key = GetKey(arr[i], k);
//		Q[key].push(arr[i]);
//	}
//}
//
//void Collect(int arr[])
//{
//	int k = 0;
//	for (int  i = 0; i < RADIX; i++)
//	{
//		while (!Q[i].empty())
//		{
//			arr[k++] = Q[i].front();
//			Q[i].pop();
//		}
//	}
//}
//
//void RadixSort(int arr[], int left, int right)
//{
//	for (int i = 0; i < K; i++)
//	{
//		//分发数据
//		Distribute(arr, left, right, i);
//
//		//回收数据
//		Collect(arr);
//	}
//}
//
//void main()
//{
//	int arr[] = { 278,109,63,930,589,184,505,269,8,83 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	//基数排序
//	RadixSort(arr, 0, size);
//
//
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	
//}