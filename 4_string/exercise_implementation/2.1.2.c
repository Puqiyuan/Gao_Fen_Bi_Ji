/*
	test result:
	~/.../exercise_implementation$ ./a.out 
	before invert: hello, world!
	after invert: !dlrow ,olleh
*/

#include <stdio.h>
#include "../basic_algorithms/string_basic_op.c"

int swap(char *ch1, char *ch2)
{
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;

	return 0;
}

int invert(Str* str)
{
	int i = 0;
	int j = str -> length - 1;
	while (i < j)
		{
			swap(&(str -> ch[i]), &(str -> ch[j]));
			++i;
			--j;
		}

	return 0;
}

int main(int argc, char *argv[])
{
	Str *str = (Str*)malloc(sizeof(Str));
	strassign(&str, "hello, world!");
	printf("before invert: %s\n", *str);
	invert(str);
	printf("after invert: %s\n", *str);
	
	return 0;
}

