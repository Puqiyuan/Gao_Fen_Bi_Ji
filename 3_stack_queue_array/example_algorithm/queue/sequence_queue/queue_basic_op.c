/*
  Test result:
  pqy7172@debian:~/.../sequence_queue$ ls               
  p65-66  queue_basic_op.c                                                        
  pqy7172@debian:~/.../sequence_queue$ gcc queue_basic_op.c                       
  pqy7172@debian:~/.../sequence_queue$ ./a.out                                    
  Init status: 1.
  The value of front: 0.                 
  The value of rear: 0.
  
  The SqQueue is empty.   

  Element 0 enQueue: OK.  
  Element 1 enQueue: OK.  
  Element 2 enQueue: OK.  
  Element 3 enQueue: OK.  
  Element 4 enQueue: OK.  
  Element 5 enQueue: OK.  
  Element 6 enQueue: OK.  
  Element 7 enQueue: Failed.                      
  The queue is full.

  DeQueue element 0: OK.
  DeQueue element 1: OK.
  DeQueue element 2: OK.
  DeQueue element 3: OK.
  DeQueue element 4: OK.
  DeQueue element 5: OK.
  DeQueue element 6: OK.
  DeQueue element 6: Failed.
  The queue is empty.
  DeQueue element 6: Failed.
  The queue is empty.
  pqy7172@debian:~/.../sequence_queue$
  [pqy7172@debian:0] 0:less 1:[tmux]                                  0.24 61% Mon 2017-07-31 16:59
 */

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


int deQueue(SqQueue *qu, int *x)
{
	if (qu -> front == qu -> rear)
		return 0;

	qu -> front = (qu -> front + 1) % maxSize;
	*x = qu -> data[qu -> front];

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

	int x;

	for (i = 0; i <= 8; i++)
		{
			if (deQueue(&qu, &x))
				{
					printf("DeQueue element %d: OK.\n", x);
					continue;
				}
			else
				{
					printf("DeQueue element %d: Failed.\n",
					       x);
					printf("The queue is empty.\n");
				}
		}
	
	return 0;
}
