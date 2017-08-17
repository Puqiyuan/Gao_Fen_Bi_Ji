#include <stdio.h>
#define maxSize 5


typedef struct
{
	int data[maxSize];
	int front, rear;
	int tag;
}Queue;


int InitQueue(Queue *qu)
{
	qu -> front = qu -> rear = 0;
	qu -> tag = 0;

	return 1;
}


int QueueEmpty(Queue qu)
{
	if (qu.front == qu.rear && qu.tag == 0)
		return 1;

	return 0;
}


int QueueFull(Queue qu)
{
	if (qu.tag == 1 && qu.front == qu.rear)
		return 1;

	return 0;
}


int enQueue(Queue *qu, int x)
{
	if (QueueFull(*qu) == 1)
		return 0;

	else
		{
			qu -> data[qu -> rear] = x;
			qu -> rear = (qu -> rear + 1) % maxSize;
			qu -> tag = 1;
		}

	return 1;
}


int deQueue(Queue *qu, int *x)
{
	if (QueueEmpty(*qu) == 1)
		return 0;

	else
		{
			//qu -> front = (qu -> front + 1) % maxSize;
			*x = qu -> data[qu -> front];
			qu -> front = (qu -> front + 1) % maxSize;
			qu -> tag = 0;
		}

	return 1;
}


int main(int argc, char *argv[])
{
	Queue Q;

        InitQueue(&Q);

        enQueue(&Q, 2);
        printf("Enqueue 2: OK.\n");
        enQueue(&Q, 1);
        printf("Enqueue 1: OK.\n");

        int x;
        deQueue(&Q, &x);
        printf("Dequeue the first element: %d.\n", x);
        deQueue(&Q, &x);
        printf("Dequeue the second element: %d.\n", x);

        return 0;
	
	return 0;
}
