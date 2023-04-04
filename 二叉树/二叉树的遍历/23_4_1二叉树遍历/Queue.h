#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);

void QueueDestory(Queue* pq);

void QueuePush(Queue* pq,QDataType x);//��������

void QueuePop(Queue* pq);//ɾ������

QDataType QueueFront(Queue* pq);//ȡ��ͷ������

QDataType QueueBack(Queue* pq);//ȡ��β������

int QueueSize(Queue* pq);//�ж��ٸ�����

bool QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��