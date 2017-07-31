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


int enQueue(SqQueue *qu, int x)
{
	if ((qu -> rear + 1) % maxSize == qu -> front)
		return 0;

	qu -> rear = (qu -> rear + 1) % maxSize;
	qu -> data[qu -> rear] = x;

	return 1;
}


int main(int argc, char *argv[])
{
	SqQueue qu;

	printf("Init status: %d.\n", InitQueue(&qu));
	printf("The value of front: %d.\n", qu.front);
	printf("The value of rear: %d.\n", qu.rear);
	printf("\n");

	if (QueueEmpty(qu))
		printf("The SqQueue is empty.\n");
	else
		printf("The SqQueue is not empty.\n");

	printf("\n");

	int i;

	for (i = 0; i <= 8; i++)
		{
			if (enQueue(&qu, i))
				{
					printf("Element %d enQueue: OK.\n", i);
					continue;
				}
			else
				{
					printf("Element %d enQueue: Failed.\n",
					       i);
					printf("The queue is full.\n");
					break;
				}
		}

	printf("\n");
		
	
	return 0;
}
