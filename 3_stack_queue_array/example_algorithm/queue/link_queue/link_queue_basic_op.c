#include <stdio.h>


typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode;


typedef struct 
{
	QNode *front;
	QNode *rear;
	
}LiQueue;


int InitQueue(LiQueue *lqu)
{
	lqu -> front = lqu -> rear = NULL;
	
	return 1;
}


int QueueEmpty(LiQueue *lqu)
{
	if (lqu -> rear == NULL || lqu -> front == NULL)
		return 1;

	return 0;
}


int main(int argc, char *argv[])
{
	LiQueue lqu;

	if (InitQueue(&lqu))
	{
		printf("Init link queue: OK.\n");
		printf("front: %p, rear: %p.\n\n", lqu.front, lqu.rear);
	}
	else
		printf("Init link queue: Failed.\n\n");

	if (QueueEmpty(&lqu))
		printf("The queue is empty.\n\n");
	else
		printf("The queue is not empty.\n\n");
	
	return 0;
}

