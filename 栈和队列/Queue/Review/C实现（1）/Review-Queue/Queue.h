#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QInit(Queue* ps);

void QPush(Queue* ps, QDataType x);

void QPop(Queue* ps);

QDataType QFront(Queue* ps);

QDataType QBack(Queue* ps);

int QSize(Queue* ps);

bool QueueEmpty(Queue* ps);

void QDestroy(Queue* ps);

