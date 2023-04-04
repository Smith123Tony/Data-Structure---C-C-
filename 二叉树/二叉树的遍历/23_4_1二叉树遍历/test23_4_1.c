#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"


typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//�½����
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

//ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
	
}

//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int size = 0;

////�����н�������1
//int TreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//		return;
//	(*psize)++;
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

//�����Ľ�������2
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left)
		+ TreeSize(root->right)
		+ 1;
}

//�����ĸ߶�
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


int TreeKLevel(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	int leftK = TreeKLevel(root->left, k - 1);
	int rightK = TreeKLevel(root->right, k - 1);

	return leftK + rightK;
}

//����������ֵΪx�Ľ��
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* lret = BinaryTreeFind(root->left, x);
	if (lret)
		return lret;
	BTNode* rret = BinaryTreeFind(root->right, x);
	if (rret)
		return rret;
	return NULL;
}

//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		//frontָ��Ĳ��Ƕ��еĽ�㣬�������Ľ��
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}


	QueueDestory(&q);
}

int main()
{
	BTNode* root = CreatTree();
	//PreOrder(root);//ǰ�����
	//InOrder(root);//�������
	//PostOrder(root);//�������


	////�����Ľ�㷨1
	/*int size1 = 0;
	TreeSize(root, &size1);
	printf("TreeSize:%d\n", size1);

	int size2 = 0;
	TreeSize(root, &size2);
	printf("TreeSize:%d\n", size2);*/


	////�����Ľ�㷨2
	//printf("TreeSize:%d\n", TreeSize(root));
	//printf("TreeSize:%d\n", TreeSize(root));
	//printf("TreeSize:%d\n", TreeSize(root));


	////�����ĸ߶�
	//printf("TreeHeight:%d\n", TreeHeight(root));

	//printf("TreeKLevel:%d\n", TreeKLevel(root, 1));
	
	////����������ֵΪx�Ľ��
	//printf("BinaryTreeFind:%p\n", BinaryTreeFind(root, 5));
	//printf("BinaryTreeFind:%p\n", BinaryTreeFind(root, 0));

	LevelOrder(root);

	return 0;
}