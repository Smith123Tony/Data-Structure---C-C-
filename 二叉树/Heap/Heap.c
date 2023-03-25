#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//��ʼ��
void HeapInit(HP* php)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType)*4);
	if (php->a == NULL)
	{
		perror("malloc fail\n");
		return;
	}
	php->size = 0;
	php->capacity = 4;
}

void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	//���׾���(����-1)/2
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}		
	}
}

//��������
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	//��Ȼ�ǲ������ݣ���ô����Ҫ����Ƿ���Ҫ����
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;//size�����һ�����ݵ���һ�����ݵ��±�
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//ɾ������
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));//û������ʱ�Ͳ�Ҫɾ����
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}