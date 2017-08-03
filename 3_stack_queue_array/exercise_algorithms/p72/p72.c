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


int isEmpty(SqStack st)
{
        if (st.top == -1)
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


