/*
  Test result:

  pqy7172@debian:~/.../60_1$ ls
  a.out*  p60_1  p60_1.c
  pqy7172@debian:~/.../60_1$ gcc p60_1.c 
  pqy7172@debian:~/.../60_1$ ./a.out 
  Inited link stack: OK
  pqy7172@debian:~/.../60_1$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               1.07 100% Fri 2017-07-21 22:32
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;


int InitStack(LNode *lst)
{
	lst = (LNode*)malloc(sizeof(LNode));
	lst -> next = NULL;

	return 1;
}


int main(int argc, char *argv[])
{
	LNode lst;

	if (InitStack(&lst))
		printf("Inited link stack: OK\n");

	else
		printf("Initing link stack: Failed\n");
	
	return 0;
}

