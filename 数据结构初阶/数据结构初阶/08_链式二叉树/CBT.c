#include "CBT.h"

BTNode* ByTreeNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	newnode->_left = NULL;
	newnode->_right = NULL;
	newnode->_data = x;
	return newnode;
}

//����һ����
BTNode* BinaryTreeCreate()
{
	BTNode* n1 = ByTreeNode(1);
	BTNode* n2 = ByTreeNode(2);
	BTNode* n3 = ByTreeNode(3);
	BTNode* n4 = ByTreeNode(4);
	BTNode* n5 = ByTreeNode(5);
	BTNode* n6 = ByTreeNode(6);
	BTNode* n7 = ByTreeNode(7);

	n1->_left = n2;
	n1->_right = n4;
	n2->_left = n3;
	n4->_left = n5;
	n4->_right = n6;
	n3->_right = n7;

	return n1;
}

// ������ǰ����� 
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//���ڵ�
	printf("%d ", root->_data);

	//�ݹ������ڵ�
	PrevOrder(root->_left);

	//�ݹ�����ҽڵ�
	PrevOrder(root->_right);
}

// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//�ݹ������ڵ�
	InOrder(root->_left);

	//���ڵ�
	printf("%d ", root->_data);

	//�ݹ�����ҽڵ�
	InOrder(root->_right);
}

// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	//�ݹ������ڵ�
	PostOrder(root->_left);

	//�ݹ�����ҽڵ�
	PostOrder(root->_right);

	//���ڵ�
	printf("%d ", root->_data);
}

// ��������ڵ����
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return TreeSize(root->_left) + TreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

//��������ĸ߶�
int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int LeftHeight = TreeHeight(root->_left);
	int RightHeight = TreeHeight(root->_right);

	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}

// ��������k��ڵ����
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return TreeLevelKSize(root->_left, k-1) + TreeLevelKSize(root->_right, k-1);
}