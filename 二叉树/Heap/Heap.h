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

//初始化
void HeapInit(HP* php);

//插入数据
void HeapPush(HP* php,HPDataType x);

//删除数据
void HeapPop(HP* php);

//取堆顶数据
HPDataType HeapTop(HP* php);

//是否为空
bool HeapEmpty(HP* php);

//堆中元素的个数
int HeapSize(HP* php);

void HeapDestroy(HP* php);

void HeapInitArray(HP* php, int* a, int n);

void AdjustDown2(int* a, int n, int parent);