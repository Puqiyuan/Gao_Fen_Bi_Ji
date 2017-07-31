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


