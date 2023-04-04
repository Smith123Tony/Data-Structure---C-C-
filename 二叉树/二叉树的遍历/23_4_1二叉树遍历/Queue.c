#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//��ʼ��
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

//ɾ��
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	//if (pq->head == NULL)
	//{
	//	return;
	//}//����Ĵ���
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

QDataType QueueBack(Queue* pq)//ȡ��β������
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

QDataType QueueFront(Queue* pq)//ȡ��ͷ������
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

int QueueSize(Queue* pq)//�ж��ٸ�����
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