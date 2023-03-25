#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

int main()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 4);
	HeapPush(&hp, 18);
	HeapPush(&hp, 42);
	HeapPush(&hp, 12);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);

	int i = 0;
	scanf("%d", &i);

	while (!HeapEmpty(&hp) && i--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	return 0;
}