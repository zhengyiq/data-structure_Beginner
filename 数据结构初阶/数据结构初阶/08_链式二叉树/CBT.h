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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate();
// 二叉树销毁
void TreeDestory(BTNode** root);
// 二叉树节点个数
int TreeSize(BTNode* root);
// 二叉树叶子节点个数
int TreeLeafSize(BTNode* root);
//求二叉树的高度
int TreeHeight(BTNode* root);
// 二叉树第k层节点个数
int TreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void PrevOrder(BTNode* root);
// 二叉树中序遍历
void InOrder(BTNode* root);
// 二叉树后序遍历
void PostOrder(BTNode* root);
// 层序遍历
void TreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int TreeComplete(BTNode* root);