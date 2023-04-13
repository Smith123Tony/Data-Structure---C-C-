#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void GetNext(char* sub, int* next, int lenSub)
{
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int k = 0;
	while (i < lenSub)
	{
		if (k == -1 || sub[i - 1] == sub[k])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP(char* str, char* sub, int pos)
{
	assert(str != NULL && sub != NULL);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr == 0 || lenSub == 0)
		return -1;
	if (pos < 0 || pos >= lenStr)
		return -1;

	int* next = (int*)malloc(sizeof(int) * lenSub);
	assert(next != NULL);

	GetNext(sub, next, lenSub);

	int i = pos;//±éÀúÖ÷´®
	int j = 0;//±éÀú×Ó´®

	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= lenSub)
	{
		return i - j;
	}
	return -1;
}

int main()
{

	printf("%d\n", KMP("ababcabcdabcde", "abcd", 0));
	printf("%d\n", KMP("ababcabcdabcde", "abcdf", 0));
	printf("%d\n", KMP("ababcabcdabcde", "ab", 0));
	return 0;
}



////¸´Ï°Ã°ÅÝÅÅÐò
//#include<stdio.h>
//void BubbleSort(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			int tmp = 0;
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//
//void PrintArr(int arr[], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,5,1,3,7,8,4,2,6,10 };
//	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
//	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}