#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"


void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->capacity = 4;
	ps->top = 0;
}

void StackPush(Stack* ps, STDatatype x)
{
	assert(ps);

	//检查是否需要扩容
	if (ps->capacity == ps->top)
	{
		STDatatype* tmp = (STDatatype*)realloc(ps->a, sizeof(STDatatype) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a == NULL;
	ps->capacity = 0;
	ps->top = 0;
}

STDatatype StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}



////leetcode.20 有效的括号
//bool isValid(char* s) {
//	Stack st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//		}
//		else
//		{
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			STDatatype tmp = StackTop(&st);
//			StackPop(&st);
//			if (tmp != '(' && *s == ')'
//				|| tmp != '[' && *s == ']'
//				|| tmp != '{' && *s == '}')
//			{
//				StackDestroy(&st);
//				return false;
//			}
//		}
//		s++;
//	}
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}