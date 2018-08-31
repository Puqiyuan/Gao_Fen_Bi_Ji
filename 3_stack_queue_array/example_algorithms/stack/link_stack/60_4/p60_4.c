/*
  Test result:
  pqy7172@debian:~/.../60_4$ ls
  a.out*  p60_4  p60_4.c
  pqy7172@debian:~/.../60_4$ gcc p60_4.c 
  pqy7172@debian:~/.../60_4$ ./a.out 
  Push 3: OK.
  Push 4: OK.
  Push 1: OK.
  Push 34: OK.
  After push some elements:
  34 1 4 3 
  Pop element 1: 34
  Pop element 2: 1
  Pop element 3: 4
  Pop element 4: 3
  pqy7172@debian:~/.../60_4$ 
  [pqy7172@debian:0] 0:bash                                           0.08 87% Wed 2017-07-26 16:03
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


int pop(LNode *lst, int *x)
{
	LNode *p;

	if (lst -> next == NULL)
		return 0;

	p = lst -> next;
	*x = p -> data;
	lst -> next = p -> next;
	free(p);

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

	int d;

	for (i = 0; i <= 3; i++)
		{
			pop(lst, &d);
			printf("Pop element %d: %d\n", i + 1, d);
		}
		
	return 0;
}
