#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;


int InitStack (LNode *lst)
{
	lst = NULL;
	printf("%p\n", lst);

	return 1;
}


int isEmpty (LNode *lst)
{
	if (lst == NULL)
		return 1;

	else
		return 0;
	
}


int push (LNode *lst, int x)
{
	LNode *p;

	if (! (p = (LNode *)malloc(sizeof(LNode))) )
		return 0;
	
	p -> data = x;
	p -> next = lst;
	lst = p;

	printf("lst -> next -> data: %d\n", lst -> next -> data);

	return 1;
}


int pop (LNode *lst, int *x)
{
	LNode *p;
	if (lst == NULL)
		return 0;
	p = lst;

	*x = p -> data;
	lst = p -> next;
	//free(p);
	return 1;
}


int main(int argc, char *argv[])
{
	LNode* lst = (LNode*)malloc(sizeof(LNode));
	int e[3] = {12, -1, 9}, i;

	for (i = 0; i <= 2; i++)
		{
			if (push(lst, e[i]))
				printf ("Push %d element %d: OK.\n", i + 1, e[i]);

			else
				printf ("Push %d element %d: Failed.\n",
					i + 1, e[i]);
		}

	int *d = (int*)malloc(sizeof(int));

	for (i = 0; i <= 2; i++)
		{
			if (pop(lst, d))
				printf("Pop element %d: %d.\n", i + 1, *d);

			else
				printf("Pop element %d: Failed.\n", i + 1);
		}

	if (isEmpty(lst))
		printf("Now the stack is empty after pop all elemetns");
	
	return 0;
}
