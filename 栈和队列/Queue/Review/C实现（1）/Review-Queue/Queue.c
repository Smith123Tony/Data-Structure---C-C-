#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QInit(Queue* ps)
{
	assert(ps);
	ps->head = ps->tail = NULL;
	ps->size = 0;
}

void QPush(Queue* ps, QDataType x)
{
	assert(ps);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (ps->head == NULL)
	{
		assert(ps->tail == NULL);
		ps->head = ps->tail = newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = newnode;
	}
	ps->size++;
}

void QPop(Queue* ps)
{
	assert(ps);
	assert(ps->head);
	/*QNode* next = ps->head->next;
	free(ps->head);
	ps->head = next;
	if (ps->head == NULL)
		ps->tail = NULL;*/
	if (ps->head->next == NULL)
	{
		free(ps->head);
		ps->head = ps->tail = NULL;
	}
	else
	{
		QNode* next = ps->head->next;
		free(ps->head);
		ps->head = next;
	}
	ps->size--;
}

QDataType QFront(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->head->data;
}

QDataType QBack(Queue* ps)
{
	assert(ps);
	assert(!QueueEmpty(ps));
	return ps->tail->data;
}

int QSize(Queue* ps)
{
	assert(ps);
	return ps->size;
}

bool QueueEmpty(Queue* ps)
{
	assert(ps);
	return ps->size == 0;
}

void QDestroy(Queue* ps)
{
	assert(ps);
	QNode* cur = ps->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	ps->head = ps->tail = NULL;
	ps->size = 0;
}