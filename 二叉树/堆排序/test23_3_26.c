#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(int* a, int child)
{
	//父亲就是(孩子-1)/2
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整，基础为小堆
void AdjustDown1(int* a, int n, int parent)
{
	int child = parent * 2 + 2;
	while (child < n)
	{
		if (child < n && a[child - 1] < a[child])
		{
			child--;
		}
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整，基础为大堆
void AdjustDown2(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//向上调整建堆
	for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}

	////向下调整建堆
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	AdjustDown1(a, n, i);
	//}

	int end = n - 1;
	while (end > 0)
	{
		swap(&a[end], &a[0]);
		AdjustDown1(a, end, 0);
		//AdjustDown2(a, end, 0);
		end--;
	}
}

int main()
{
	int a[10] = { 8,5,2,1,4,7,9,6,3,10 };

	HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}