#define _CRT_SECURE_NO_WARNINGS 1


void Swap(int* a1, int* a2)
{
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		int mini = left;
		int maxi = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[left], &a[mini]);
		if (left == maxi)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);
		left++;
		right--;
	}
}


void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}


}

void TestSelectSort()
{
	int a[] = { 3,5,1,6,2,3,7,9,0,8 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	printf("\n");

	SelectSort(a, sizeof(a) / sizeof(a[0]));

	PrintArray(a, sizeof(a) / sizeof(a[0]));
	printf("\n");
}

#include<stdio.h>

int main()
{
	TestSelectSort();
	return 0;
}