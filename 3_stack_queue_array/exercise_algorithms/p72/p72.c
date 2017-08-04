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


int main(int argc, char *argv[])
{
	SqStack s1, s2;
	
	initStack(&s1);
	initStack(&s2);
	
	int x[11] = {2, 4, 1, 0, -1, 99, 101, -12, 3, 78, 999}, i;

	for (i = 0; i <= 10; i++)
		{
			if (enqueue(&s1, &s2, x[i]) == 1)
				printf("Enqueue element %d: OK, value: %d.\n",
				       i, x[i]);

						else
				printf("Enqueue element %d: Failed, value: %d.\n",
				       i, x[i]);
		}
	
	return 0;
}
