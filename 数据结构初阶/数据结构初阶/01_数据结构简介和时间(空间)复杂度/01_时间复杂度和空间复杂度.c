#define _CRT_SECURE_NO_WARNINGS 1


	
	//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
	//输出 : [5, 6, 7, 1, 2, 3, 4]
	//解释 :
	//向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
	//向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
	//向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]

	//来源：力扣（LeetCode）
//#include <stdio.h>
//
//void rotate(int* nums, int numsSize, int k) {
//	int arr[5];
//	for (int i = 0; i < k; ++i)
//	{
//		*(arr + (k - 1 - i)) = *(nums + (numsSize - 1 - i));
//	}
//	for (int j = 0; j < k + 1; ++j)
//	{
//		*(nums + (numsSize - 1 - j)) = *(nums + (numsSize - 1 - k - j));
//	}
//	for (int m = 0; m < k; ++m)
//	{
//		*(nums + m) = *(arr + m);
//	}
//
//}
//
//
//int main(void)
//{
//	int num[7] = { 1,2,3,4,5,6,7 };
//	//int num[] = { -1, -100, 3, 99 };
//
//	rotate(num, 7, 5);
//	for (int  i = 0; i < 7; i++)
//	{
//		printf("%d, ", num[i]);
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <time.h>

//int main(void)
//{
//	clock_t begin_time = clock();
//	int n = 0;
//	for (size_t i = 0; i < 10000000; i++)
//	{
//		n++;
//	}
//	clock_t end_time = clock();
//	printf("%f秒", (double)(end_time - begin_time) / CLOCKS_PER_SEC);
//
//	return 0;
//}


//#include <stdio.h>
//
//int search_max(int* str, int sz)
//{
//	int* fir = str;
//	int* end = str + sz - 1;
//	int ret = 0;
//	int sum = 0;
//
//	while (fir != end)
//	{
//		sum = *fir + *end;
//		if (sum >= ret)
//		{
//			ret = sum;
//		}
//		fir++;
//	}
//	return ret;
//}
//
//int main(void)
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d ", search_max(arr, sz));
//	return 0;
//}
