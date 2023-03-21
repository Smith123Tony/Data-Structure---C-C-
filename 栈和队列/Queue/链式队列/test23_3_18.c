#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void TestQueue1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	//QueuePop(&q);

	//printf("%d\n", QueueFront(&q));
	//printf("%d\n", QueueFront(&q));

	QueuePush(&q, 10);
	QueuePush(&q, 20);

	QueueDestory(&q);

}

void TestQueue2()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");
}

//测试队列为空时但想要取数据就会直接报错
void TestQueue3()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QDataType back = QueueBack(&q);
}

int main()
{
	//TestQueue1();
	//TestQueue2();
	TestQueue3();
	return 0;
}