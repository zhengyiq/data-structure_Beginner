#include "CBT.h"
#include "Q1.h"
void TestTree1()
{
	BTNode* root = BinaryTreeCreate();
	PrevOrder(root);

	printf("\n");
	InOrder(root);

	printf("\n");
	PostOrder(root);
}

void TestTree2()
{
	BTNode* root = BinaryTreeCreate();

	printf("TreeSize:%d", TreeSize(root));
}

void TestTree3()
{
	BTNode* root = BinaryTreeCreate();

	printf("TreeLeafSize:%d", TreeLeafSize(root));
}

void TestTree4()
{
	BTNode* root = BinaryTreeCreate();
	printf("TreeHeight:%d", TreeHeight(root));
}

void TestTree5()
{
	BTNode* root = BinaryTreeCreate();
	printf("TreeLevelKSize:%d", TreeLevelKSize(root, 4));
}

void TestTree6()
{
	BTNode* root = BinaryTreeCreate();
	BTNode* ret = TreeFind(root, 8);
	if (ret != NULL)
	{
		printf("The Tree has the Node:%d\n", ret->_data);
	}
	else
	{
		printf("The Tree don't have the Node");
	}
}

void TestTree7()
{
	BTNode* root = BinaryTreeCreate();
	TreeLevelOrder(root);
}
int main()
{
	TestTree6();
	return 0;
}