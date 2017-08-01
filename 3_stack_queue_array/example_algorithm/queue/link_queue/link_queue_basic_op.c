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
	
	
	return 0;
}

