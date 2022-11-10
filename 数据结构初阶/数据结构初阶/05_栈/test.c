#include "Stack.h"

void TestStack01()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	//StackPop(&s);//err
}

int main()
{
	TestStack01();
	return 0;
}