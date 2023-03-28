#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//��ʼ��
void HeapInit(HP* php);

//��������
void HeapPush(HP* php,HPDataType x);

//ɾ������
void HeapPop(HP* php);

//ȡ�Ѷ�����
HPDataType HeapTop(HP* php);

//�Ƿ�Ϊ��
bool HeapEmpty(HP* php);

//����Ԫ�صĸ���
int HeapSize(HP* php);

void HeapDestroy(HP* php);

void HeapInitArray(HP* php, int* a, int n);

void AdjustDown2(int* a, int n, int parent);