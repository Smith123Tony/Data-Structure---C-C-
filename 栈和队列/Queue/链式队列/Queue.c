#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//删除
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//if (pq->head == NULL)
	//{
	//	return;
	//}//温柔的处理
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail=NULL;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

QDataType QueueBack(Queue* pq)//取队尾的数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

QDataType QueueFront(Queue* pq)//取队头的数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

int QueueSize(Queue* pq)//有多少个数据
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}