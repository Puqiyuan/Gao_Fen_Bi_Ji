/*
	test result:
	~/.../exercise_implementation$ ./a.out 
	before delete: hello, world!
	after delete: hell, wrld!
*/

#include <stdio.h>
#include "../basic_algorithms/string_basic_op.c"

int dell(Str *str, char ch)
{
	if (str -> length != 0)
		{
			int sum = 0;
			int i;
			int j;
			for (i = 0; i < str -> length; ++i)
				if (str -> ch[i] == ch)
					++sum;
	

			if (sum != 0)
				{
					char* temp_ch = (char*)malloc(sizeof(char) * (str -> length - sum + 1));
					for (i = 0, j = 0; i < str -> length; ++i)
						if (str -> ch[i] != ch)
							temp_ch[j++] = str -> ch[i];
					temp_ch[j] = '\0';
					str -> length = str -> length - sum;
					free(str -> ch);
					str -> ch = temp_ch;
				}
		} 
}


int main(int argc, char *argv[])
{
	Str* str = (Str*)malloc(sizeof(Str));
	strassign(&str, "hello, world!");
	printf("before delete: %s\n", *str);
	dell(str, 'o');
	printf("after delete: %s\n", *str);
		
	return 0;
}
