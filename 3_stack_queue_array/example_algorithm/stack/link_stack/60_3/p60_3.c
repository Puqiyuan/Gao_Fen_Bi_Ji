/*
  Test result:
  pqy7172@debian:~/.../60_3$ ls
  a.out*  p60_3  p60_3.c
  pqy7172@debian:~/.../60_3$ gcc p60_3.c 
  pqy7172@debian:~/.../60_3$ ./a.out 
  Push 3: OK.
  Push 4: OK.
  Push 1: OK.
  Push 34: OK.
  After push some elements:
  34 1 4 3 
  pqy7172@debian:~/.../60_3$ 
  [pqy7172@debian:0] 0:bash 1:bash                                    0.34 57% Tue 2017-07-25 11:00
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;


int push(LNode *lst, int x)
{
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));

	p -> next = NULL;

	p -> data = x;
	p -> next = lst -> next;
	lst -> next = p;

	return 1;
}



int display(LNode *lst)
{
	LNode *p = (LNode*)malloc(sizeof(LNode));
	p = lst;
	
	while (p -> next != NULL)
		{
			printf("%d ", p -> next -> data);
			p = p -> next;
		}

	printf("\n");

	return 1;
}


int main(int argc, char *argv[])
{
	LNode *lst = (LNode*)malloc(sizeof(LNode));

	int x[4] = {3, 4, 1, 34}, i;

	for (i = 0; i <= 3; i++)
		{
			if (push(lst, x[i]) > 0)
				printf("Push %d: OK.\n", x[i]);

			else
				{
					printf("Push %d: Failed.\n", x[i]);
					return -1;
				}
		}

	printf("After push some elements:\n");

	display(lst);

	return 0;
}
