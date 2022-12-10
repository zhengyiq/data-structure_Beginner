#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	////将指向数组的指令置零
	//ps->_data = NULL;
	////将容量设为0
	//ps->_capacity = 0;
	////将栈顶设为0位置
	//ps->_top = 0;

	STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * DEFAULTY_CAPACITY);
	if (tmp == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	ps->_data = tmp;
	ps->_top = 0;
	ps->_capacity = DEFAULTY_CAPACITY;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->_data, ps->_capacity*2*sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps->_data = tmp;
		ps->_capacity *= 2;
	}
	ps->_data[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	ps->_top--; 
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top >= 0);
	return ps->_data[ps->_top-1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	assert(ps->_top >= 0);
	return ps->_top;
}

bool StackEmpty(Stack* ps)
{
	return ps->_top == 0;
}

void StackDestroy(Stack* ps)
{
	free(ps->_data);
	ps->_data = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

