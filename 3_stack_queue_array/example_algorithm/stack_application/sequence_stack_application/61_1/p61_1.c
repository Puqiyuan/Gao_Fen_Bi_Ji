/*
  Test result:
  pqy7172@debian:~/.../61_1$ ./a.out 
  ()()()()
  The expression is right.
  pqy7172@debian:~/.../61_1$ ./a.out 
  )()
  The expresession is wrong.
  pqy7172@debian:~/.../61_1$ ./a.out 
  ()()((()
  The expresession is wrong.
  pqy7172@debian:~/.../61_1$ 
  [pqy7172@debian:0] 0:bash                                           0.43 67% Wed 2017-07-26 16:46
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 100

int match(char exp[], int n)
{
	char stack[maxSize];
	int top = -1;

	int i;
	for (i = 0; i <= n - 1; ++i)
		{
			if (exp[i] == '(')
				stack[++top] = '(';

			if (exp[i] == ')')
				{
					if (top == -1)
						return 0;

					else
						--top;
				}
		}

	if (top == -1)
		return 1;

	else
		return 0;
}


int main(int argc, char *argv[])
{
	char exp[100];
	scanf("%s", exp);

	int len = strlen(exp);
	
	if (match(exp, len))
		printf("The expression is right.\n");

	else
		printf("The expresession is wrong.\n");
	
	return 0;
}
