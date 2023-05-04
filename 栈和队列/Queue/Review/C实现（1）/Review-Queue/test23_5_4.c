#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main()
{
	Queue q;
	QInit(&q);
	QPush(&q, 1);
	QPush(&q, 2);
	QPush(&q, 3);
	QPush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QFront(&q));
		QPop(&q);
	}
	printf("\n");
	return 0;
}