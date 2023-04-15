#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//¸Ä½øÃ°ÅÝÅÅÐò
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		bool exchange = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
			exchange = true;
		}
		if (exchange == false)
			break;
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void TestBubbleSort()
{
	int a[] = { 6,0,9,1,5,3,8,7,4,2,10 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	printf("\n");

	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	printf("\n");
}

int main()
{
	TestBubbleSort();
	return 0;
}