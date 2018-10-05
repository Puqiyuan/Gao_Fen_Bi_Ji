/*
	Test result:
	~/.../example_algorithms$ make
	gcc string_basic_op.c -o test
	./test
	test for strassign() function:
	this is a assign string.
	~/.../example_algorithms$ 
	[pqy7172@debian:0] 0:ss-local 1:bash                                                0.59 99% Fri 2018-10-05 21:10
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char *ch;
	int length;
}Str;

int strassign(Str** str, char* ch)
{
	if ((*str) -> ch)
		free((*str) -> ch);
	int len = 0;
	char *c = ch;

	while (*c)
		{
			++len;
			++c;
		}

	if (len == 0)
		{
			(*str) -> ch = NULL;
			(*str) -> length = 0;
			return 1;
		}

	else
		{
			(*str) -> ch = (char*)malloc(sizeof(char) * (len + 1));

			if ((*str) -> ch == NULL)
				return 0;

			else
				{
					c = ch;
					for (int i = 0; i <= len; ++i, ++c)
						(*str) -> ch[i] = *c;
					(*str) -> length = len;
					return 1;
				}
		}
}

int main(int argc, char *argv[])
{
	Str* str = (Str*)malloc(sizeof(Str));

	printf("test for strassign() function:\n");
	strassign(&str, "this is a assign string.");
	printf("%s\n", *str);
	
	return 0;
}
