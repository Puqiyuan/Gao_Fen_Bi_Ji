#include <stdio.h>
#include <stdlib.h>


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


int enQueue(LiQueue *lqu, int x)
{
	QNode *p = (QNode*)malloc(sizeof(QNode));

	p -> data = x;
	p -> next = NULL;

	if (lqu -> rear == NULL || lqu -> front == NULL)
		lqu -> front = lqu -> rear = p;
	else
		{
			lqu -> rear -> next = p;
			lqu -> rear = p;
		}

	return 1;
}


int deQueue(LiQueue *lqu, int *x)
{
	QNode *p;
	if (lqu -> rear == NULL)
		return 0;
	else
		p = lqu -> front;

	if (lqu -> front == lqu -> rear)
		lqu -> front = lqu -> rear = NULL;

	else
		lqu -> front = lqu -> front -> next;

	*x = p -> data;
	free(p);
	
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

	if (QueueEmpty(&lqu))
		printf("The queue is empty.\n\n");
	else
		printf("The queue is not empty.\n\n");

	int x[3] = {-1, 0, 99}, i;
	for (i = 0; i <= 2; i++)
		{
			enQueue(&lqu, x[i]);
			printf("The element %d enQueue: OK.\n", x[i]);
		}
	printf("\n");

	int *d;
	for (i = 0; i <= 3; i++)
		{
			if(deQueue(&lqu, d))
				printf("deQueue element is OK, value: %d\n",*d);
			else
				printf("deQueue element is Failed.\n");
		}
	
	return 0;
}
