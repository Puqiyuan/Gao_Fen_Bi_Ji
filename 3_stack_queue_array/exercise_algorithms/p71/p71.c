#include <stdio.h>
#include <stdlib.h>

#define maxSize 10

typedef struct
{
	int elem[maxSize];
	int top[2];
}SqStack;


int InitStack(SqStack *st)
{
	st -> top[0] = -1;
	st -> top[1] = maxSize;

	return 1;
}


int push(SqStack *st, int stNo, int x)
{
	if (st -> top[0] + 1 < st -> top[1])
		{
			if (stNo == 0)
				{
					++(st -> top[0]);
					st -> elem[st -> top[0]] = x;
					return 1;
				}

			else if (stNo == 1)
				{
					--(st -> top[1]);
					st -> elem[st -> top[1]] = x;
					return 1;
				}
			
			else
				return -1;
		}

	return 0;
}


int test_push(SqStack *st)
{
	int x[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i, flag, stNo;
	
	for (i = 0; i <= 10; i++)
		{
			if (i % 2 == 0)
				stNo = 0;
			else
				stNo = 1;

			flag = push(st, stNo, x[i]);

			if (flag == 1)
				{
					printf("push element %d: OK.\n", x[i]);
					continue;
				}
			
			else if (flag == -1)
				{
					printf("Sorry your stNo is wrong.\n");
					break;
				}

			else if (flag == 0)
				{
					printf("Sorry the stack is full.\n");
					break;
				}
		}

	printf("\n");

	return 1;
}


int pop(SqStack *st, int stNo, int *x)
{
	if (stNo == 0)
		{
			if (st -> top[0] != -1)
				{
					*x = st -> elem[st -> top[0]];
					--(st -> top[0]);
					return 1;
				}
			else
				return 0;
			
		}
	else if (stNo == 1)
		{
			if (st -> top[1] != maxSize)
				{
					*x = st -> elem[st -> top[1]];
					++(st -> top[1]);
					return 1;
				}
			else
				return 0;
		}

	return -1;
}


int test_pop(SqStack *st)
{
	int *x = (int*)malloc(sizeof(int));
	int i, stNo, flag;

	for (i = 0; i <= 10; i++)
		{
			if (i % 2 == 0)
				stNo = 0;
			else
				stNo = 1;

			flag = pop(st, stNo, x);

			if (flag == 1)
				{
					if (stNo == 0)
						{
							printf("Pop element %d of stack 0: OK, value: %d.\n", i, *x);
							continue;
						}
					else if (stNo == 1)
						{
							printf("Pop element %d of stack 1: OK, value: %d.\n", i, *x);
							continue;
						}
					
				}

			else if (flag == 0)
				{
					if (stNo == 0)
						printf("The stack 0 is empty.\n");

					else if (stNo == 1)
						printf("The stack 1 is empty.\n");
				}

			else
				printf("The stNo is wrong.\n");
				
		}

	return 1;
}


int main(int argc, char *argv[])
{
	SqStack st;

	printf("Test for InitStack:\n");
	InitStack(&st);
	printf("Init stack: OK, bottom1: %d, bottom2: %d.\n\n",
	       st.top[0], st.top[1]);

	printf("Test for push operation:\n");
	test_push(&st);

	printf("Test for pop operation:\n");
	test_pop(&st);
	
	return 0;
}
