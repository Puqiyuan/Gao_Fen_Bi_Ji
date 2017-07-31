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


int main(int argc, char *argv[])
{
	SqQueue qu;

	printf("Init status: %d.\n", InitQueue(&qu));
	printf("The value of front: %d.\n", qu.front);
	printf("The value of rear: %d.\n", qu.rear);
	
	return 0;
}
