#include <stdio.h>
#define maxSize 8


typedef struct
{
	int data[maxSize];
	int front;
	int rear;
}SqQueue;


int InitQueue(SqQueue *qu)
{
	qu -> front = qu -> rear = 0;

	return 1;
}


int QueueEmpty(SqQueue qu)
{
	if (qu.front == qu.rear)
		return 1;

	return 0;
}


int main(int argc, char *argv[])
{
	SqQueue qu;

	printf("Init status: %d.\n", InitQueue(&qu));
	printf("The value of front: %d.\n", qu.front);
	printf("The value of rear: %d.\n", qu.rear);

	if (QueueEmpty(qu))
		printf("The SqQueue is empty.\n");
	else
		printf("The SqQueue is not empty.\n");
		
	
	return 0;
}
