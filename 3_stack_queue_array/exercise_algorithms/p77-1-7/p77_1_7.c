/*
  Test result:
  pqy7172@debian:~/.../p77-1-7$ make run 
  gcc -Wall p77_1_7.c -o test
  ./test
  Enqueue 2: OK.
  Enqueue 1: OK.
  Dequeue the first element: 2.
  Dequeue the second element: 1.
  pqy7172@debian:~/.../p77-1-7$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               0.12 100% Thu 2017-08-17 20:1
 */

#include <stdio.h>
#define maxSize 5


typedef struct
{
	int data[maxSize];
	int front, rear;
}cyqueue;


int init_queue(cyqueue *Q)
{
	Q -> front = Q -> rear = 0;

	return 1;
}


int enqueue(cyqueue *Q, int x)
{
	if (Q -> rear == (Q -> front - 1 + maxSize) % maxSize)
		return 0;
	
	else
		{
			Q -> data[Q -> front] = x;
			Q -> front = (Q -> front - 1 + maxSize) % maxSize;
		}

	return 1;
}


int dequeue(cyqueue *Q, int *x)
{
	if (Q -> front == Q -> rear)
		return 0;

	else
		{
			*x = Q -> data[Q -> rear];
			Q -> rear = (Q -> rear - 1 + maxSize) % maxSize;
		}

	return 1;
}


int main(int argc, char *argv[])
{
	cyqueue Q;

	init_queue(&Q);

	enqueue(&Q, 2);
	printf("Enqueue 2: OK.\n");
	enqueue(&Q, 1);
	printf("Enqueue 1: OK.\n");

	int x;
	dequeue(&Q, &x);
	printf("Dequeue the first element: %d.\n", x);
	dequeue(&Q, &x);
	printf("Dequeue the second element: %d.\n", x);
		
	return 0;
}

