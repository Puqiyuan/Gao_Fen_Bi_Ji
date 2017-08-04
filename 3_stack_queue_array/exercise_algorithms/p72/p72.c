#include <stdio.h>
#include <stdlib.h>

#define maxSize 5

typedef struct
{
	int data[maxSize];
	int top;
}SqStack;


int initStack(SqStack *st)                      
{                       
        st -> top = -1; 

        return 1;       
}


int isEmpty(SqStack *st)
{
        if (st -> top == -1)
                return 1;

        return 0;
}


int push(SqStack *st, int x)               
{
        if (st -> top == maxSize - 1)              
                return 0;

        ++(st -> top);
	
        st -> data[st -> top] = x;
	
	return 1;
}


int pop(SqStack *st, int *x)
{
	if (st -> top == -1)
		return 0;

	*x = st -> data[st -> top];
	--(st -> top);

	return 1;
}


int enqueue(SqStack *s1, SqStack *s2, int x)
{
	int *y = (int*)malloc(sizeof(int));


	if (s1 -> top == maxSize - 1)
		{
			if (!isEmpty(s2))
				return 0;

			else if (isEmpty(s2))
				{
					while (!isEmpty(s1))
						{
							pop(s1, y);
							push(s2, *y);
						}
					push(s1, x);
					return 1;
				}
		}

	else
		push(s1, x);

	return 1;
}


int dequeue(SqStack *s2, SqStack *s1, int *x)
{
	int *y = (int*)malloc(sizeof(int));

	if (!isEmpty(s2))
		{
			pop(s2, x);
			return 1;
		}

	else
		{
			if (isEmpty(s1))
				return 0;

			else
				{
					while (!isEmpty(s1))
						{
							pop(s1, y);
							push(s2, *y);
						}
					pop(s2, x);
				}
		}

	return 1;
}


int queue_empty(SqStack *s1, SqStack *s2)
{
	if (isEmpty(s1) && isEmpty(s2))
		return 1;

	return 0;
}


int main(int argc, char *argv[])
{
	SqStack s1, s2;
	
	initStack(&s1);
	initStack(&s2);
	
	int x[11] = {2, 4, 1, 0, -1, 99, 101, -12, 3, 78, 999}, i;

	printf("Test for enqueue operation:\n");
	for (i = 0; i <= 10; i++)
		{
			if (enqueue(&s1, &s2, x[i]) == 1)
				printf("Enqueue element %d: OK, value: %d.\n",
				       i, x[i]);

			else
				printf("Enqueue element %d: Failed, value: %d.\n",
				       i, x[i]);
		}
	printf("\n");

	printf("Test for dequeue operation:\n");
	int *d = (int*)malloc(sizeof(int));
	for (i = 0; i <= 10; i++)
		{
			if (dequeue(&s2, &s1, d) == 1)
				printf("Dequeue element %d: OK, value: %d.\n",
				       i, *d);
			else
				printf("Dequeue element %d: Failed.\n", i);
		}
	printf("\n");

	printf("Test for queue empty operation:\n");
	if (queue_empty(&s1, &s2))
		printf("The queue is empty.\n");
	else
		printf("The queue is not empty.\n");

	
	
	return 0;
}
