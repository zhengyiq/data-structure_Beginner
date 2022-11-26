#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

#include "Q1.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate();
// ����������
void TreeDestory(BTNode** root);
// �������ڵ����
int TreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root);
//��������ĸ߶�
int TreeHeight(BTNode* root);
// ��������k��ڵ����
int TreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void PrevOrder(BTNode* root);
// �������������
void InOrder(BTNode* root);
// �������������
void PostOrder(BTNode* root);
// �������
void TreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int TreeComplete(BTNode* root);