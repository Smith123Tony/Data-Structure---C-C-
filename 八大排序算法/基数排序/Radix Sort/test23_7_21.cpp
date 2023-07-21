#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<queue>
using namespace std;

#define RADIX 10
#define K 3          //排序3轮

queue<int> Q[RADIX];

int getkey(int value, int k)
{
	int key = 0;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void distribute(int arr[], int left, int right,int k)
{
	for (int i = left; i < right; i++)
	{
		int key = getkey(arr[i], k);
		Q[key].push(arr[i]);
	}
}

void collect(int arr[])
{
	int k = 0;
	for (int i = 0; i < RADIX; i++)
	{
		while (!Q[i].empty())
		{
			arr[k++] = Q[i].front();
			Q[i].pop();
		}
	}
}
void ridixsort(int arr[], int left, int right)
{
	for (int i = 0; i < K; i++)
	{
		//分发数据
		distribute(arr, left, right, i);


		//回收数据
		collect(arr);
	}
	
}

int main()
{
	int arr[] = { 177 ,208 ,64, 910 ,586, 182, 405, 239, 83, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	ridixsort(arr, 0, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}