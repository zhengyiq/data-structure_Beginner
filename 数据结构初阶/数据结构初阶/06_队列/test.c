#include "Queue.h"

void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d ", QueueFront(&q));
	printf("%d ", QueueBack(&q));
	printf("%d ", QueueSize(&q));
	printf("%d ", QueueEmpty(&q));


	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	printf("%d ", QueueBack(&q));
	printf("%d ", QueueSize(&q));
	printf("%d ", QueueEmpty(&q));
	printf("\n");
	QueuePop(&q);
	printf("%d ", QueueSize(&q));
	printf("%d ", QueueEmpty(&q));

	QueueDestory(&q);
}


int main()
{
	TestQueue1();
	return 0;
}