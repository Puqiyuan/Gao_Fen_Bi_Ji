/* 
   Test result:
   pqy7172@debian:~/.../p77-1-3$ make run 
   gcc -Wall p77_1_3.c -o test
   ./test
   IO
   The operation sequence is legal.
   pqy7172@debian:~/.../p77-1-3$ make run 
   ./test
   OI
   The operation sequence is NOT legal.
   pqy7172@debian:~/.../p77-1-3$ 
   [pqy7172@debian:0] 0:ss-local 1:bash                               0.20 100% Tue 2017-08-15 21:31
 */

#include <stdio.h>

int Judge(char ch[])
{
	int i = 0;
	int I = 0, O = 0;

	while (ch[i] != '\0')
		{
			if (ch[i] == 'I')
				++I;

			if (ch[i] == 'O')
				++O;

			if (O > I)
				return 0;
			++i;
		}

	if (I != O)
		return 0;

	return 1;
}


int main(int argc, char *argv[])
{
	char ch[100];
	scanf("%s", ch);

	if (Judge(ch))
		printf("The operation sequence is legal.\n");

	else
		printf("The operation sequence is NOT legal.\n");
	
	return 0;
}

