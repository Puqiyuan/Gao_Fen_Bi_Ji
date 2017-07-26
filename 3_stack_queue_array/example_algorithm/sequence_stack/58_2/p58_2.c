/*
  The test result:
  pqy7172@debian:~/.../58_2$ ls
  a.out*  p58_2  p58_2.c
  pqy7172@debian:~/.../58_2$ gcc p58_2.c 
  pqy7172@debian:~/.../58_2$ ./a.out 
  The sequence stack is empty.
  pqy7172@debian:~/.../58_2$ 
  [pqy7172@debian:0] 0:ss-local 1:bash                               0.14 100% Tue 2017-07-18 11:25
 */

#include <stdio.h>               
#include <stdlib.h>
#define maxSixe 100


typedef struct              
{                       
        int data[maxSixe];                      
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


int main(int argc, char *argv[])
{
	SqStack st;
	
	initStack(&st);

	if (isEmpty(st) == 1)
		printf("The sequence stack is empty.\n");

	else
		printf("The sequence stack is not empty.\n");
	
	return 0;
}
