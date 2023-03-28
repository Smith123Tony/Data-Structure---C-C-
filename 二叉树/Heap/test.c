#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

int main()
{
	//HP hp;
	//HeapInit(&hp);
	//HeapPush(&hp, 4);
	//HeapPush(&hp, 18);
	//HeapPush(&hp, 42);
	//HeapPush(&hp, 12);
	//HeapPush(&hp, 2);
	//HeapPush(&hp, 3);


	//int i = 0;
	//scanf("%d", &i);

	//while (!HeapEmpty(&hp) && i--)
	//{
	//	printf("%d ", HeapTop(&hp));
	//	HeapPop(&hp);
	//}
	//printf("\n");
	//return 0;
	int a[10] = { 1,6,8,7,4,9,3,2,5,10 };
	AdjustDown(a, 10, 0);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

}