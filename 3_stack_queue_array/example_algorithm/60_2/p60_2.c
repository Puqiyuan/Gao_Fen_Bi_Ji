/*
  Test result:
  
  pqy7172@debian:~/.../60_2$ ls
  a.out*  p60_2  p60_2.c
  pqy7172@debian:~/.../60_2$ gcc p60_2.c 
  pqy7172@debian:~/.../60_2$ ./a.out 
  Inited link stack: OK.
  The stack is empty.
  pqy7172@debian:~/.../60_2$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               1.21 100% Fri 2017-07-21 22:54
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode;


int isEmpty(LNode *lst)
{
	if (lst -> next == NULL)
		return 1;

	return 0;
}


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
		printf("Inited link stack: OK.\n");

	else
		printf("Inited link stack: Failed.\n");
		

	if (isEmpty(&lst))
		printf("The stack is empty.\n");

	else
		printf("The stack is not empty.\n");
	
	return 0;
}
