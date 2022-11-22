#include "CBT.h"

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
int main()
{
	TestTree5();
	return 0;
}