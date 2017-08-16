#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;


typedef struct loop_queue
{
	LNode head;
	LNode *rear;
}loop_queue;


int init_queue(loop_queue *Qu)
{
	Qu -> rear = &(Qu -> head);

	return 1;
}


int EnQueue(LNode *rear, int x)
{
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s -> data = x;
	s -> next = rear -> next;
	rear -> next = s;
	rear = s;

	return 1;
}


int main(int argc, char *argv[])
{
	loop_queue Qu;

	init_queue(&Qu);
	
	EnQueue(Qu.rear, 2);
		
	return 0;
}

