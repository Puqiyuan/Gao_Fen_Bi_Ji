/*
	test result:
	~/.../exercise_algorithms$ ./a.out 
	before change: hello, world!
	after change: hellO, wOrld!
*/

#include <stdio.h>
#include "../example_algorithms/string_basic_op.c"

void trans(Str *str, char ch1, char ch2)
{
	for (int i = 0; i < str -> length; ++i)
		{
			if (str -> ch[i] == ch1)
				str -> ch[i] = ch2;
		}
}

int main(int argc, char *argv[])
{
	Str* str = (Str*)malloc(sizeof(Str));
	strassign(&str, "hello, world!");
	printf("before change: %s\n", *str);
	trans(str, 'o', 'O');
	printf("after change: %s\n", *str);
	
	return 0;
}

