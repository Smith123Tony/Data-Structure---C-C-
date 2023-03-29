#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

void SeqListInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void CheckCapacity(SL* ps)
{
	if(ps->size==ps->capacity)
	{
		if (ps->capacity == 0)
		{
			ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
			ps->capacity = 4;
		}
		else
		{
			SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
			if (tmp == NULL)
			{
				printf("realloc fail\n");
				exit(-1);
			}
			ps->a = tmp;
			ps->capacity *= 2;
		}		
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size; i >= 1; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i--)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	assert(pos >= 1 && pos <= ps->size);
	for (int i = ps->size; i >= pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 1 && pos <= ps->size);
	for (int i = pos - 1; i <= ps->size - 1 - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListDestroy(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}