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

