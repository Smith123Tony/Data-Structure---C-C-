#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (QueueSize(&q) > 1)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	printf("%d ", QueueFront(&q));
	printf("\n");
	printf("%d ", QueueSize(&q));
	QueuePush(&q, 5);
	QueuePush(&q, 6);
	printf("%d ", QueueSize(&q));
	printf("%d ", QueueFront(&q));
	printf("%d ", QueueBack(&q));
	return 0;
}