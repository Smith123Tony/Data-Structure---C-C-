#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDatatype;

typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps,STDatatype x);
void StackPop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);
STDatatype StackTop(Stack* ps);