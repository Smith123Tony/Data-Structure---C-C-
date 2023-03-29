#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

//≤‚ ‘Œ≤≤ÂŒ≤…æ
void SeqListTest1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 59);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 6);
	SeqListPrint(&sl);
	printf("\n");

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

//≤‚ ‘Õ∑≤ÂÕ∑…æ
void SeqListTest2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

//≤‚ ‘»Œ“‚Œª÷√≤Â»Î
void SeqListTest3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);
	printf("\n");
	
	SeqListInsert(&sl, 1, 4);
	SeqListPrint(&sl);
	printf("\n");

	SeqListInsert(&sl, 2, 100);
	SeqListPrint(&sl);
	printf("\n");
	SeqListDestroy(&sl);
}

//≤‚ ‘»Œ“‚Œª÷√…æ≥˝
void SeqListTest4()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);
	printf("\n");

	SeqListErase(&sl, 1);
	SeqListPrint(&sl);
	printf("\n");

	SeqListErase(&sl, 4);
	SeqListPrint(&sl);
	printf("\n");
}


int main()
{
	//SeqListTest1();
	//SeqListTest2();
	//SeqListTest3();
	//SeqListTest4();
	return 0;
}