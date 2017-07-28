/*
  Test result(Note that the result is Int):
  pqy7172@debian:~/.../62_2$ ls
  p62_2  p62_2.c
  pqy7172@debian:~/.../62_2$ gcc p62_2.c 
  pqy7172@debian:~/.../62_2$ ./a.out 
  Please input express, assume your input is correct:
  3214*++4/
  The result of the express: 2.
  pqy7172@debian:~/.../62_2$ 
  [pqy7172@debian:0] 0:make 1:bash                                    1.28 79% Fri 2017-07-28 09:48
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 100


int Op(int a, char op, int b)
{
	int res;
	
	if (op == '+')
		res =  a + b;

	else if (op == '-')
		res =  a - b;

	else if (op ==  '*')
		res = a * b;

	else if (op == '/')
		{
			if (b == 0)
				{	printf("Error: Divided by zero.\n");
					return -1;
				}

			else
				res =  a / b;
			
		}

	return res;
}


int computing(char exp[])
{
	int i, a, b, c;
	int stack[maxSize], top = -1;

	char op;

	for (i = 0; exp[i] != '\0'; ++i)
		{
			if (exp[i] >= '0' && exp[i] <= '9')
				stack[++top] = exp[i] - '0';

			else
				{
					op = exp[i];
					b = stack[top--];

					a = stack[top--];
					c = Op(a, op, b);
					stack[++top] = c;
				}
		}

	return stack[top];
}


int main(int argc, char *argv[])
{
	char exp[100];
	printf("Please input express, assume your input is correct:\n");
	
	scanf("%s", exp);

	printf("The result of the express: %d.\n", computing(exp));
	
	return 0;
}
