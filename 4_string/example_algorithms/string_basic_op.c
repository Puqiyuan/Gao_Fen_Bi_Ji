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

int strlength(Str str)
{
	return str.length;
}

int strcompare(Str s1, Str s2)
{
	for (int i = 0; i < s1.length && i < s2.length; ++i)
		if (s1.ch[i] != s2.ch[i])
			return s1.ch[i] - s2.ch[i];
	return s1.length - s2.length;
}

int concat(Str** str, Str str1, Str str2)
{
	if ((*str)->ch)
		{
			free((*str) -> ch);
			(*str) -> ch = NULL;
		}
	(*str) -> ch = (char*)malloc(sizeof(char) * (str1.length + str2.length+1));
	if ((*str) -> ch == NULL)
		return 0;
	int i = 0;
	while (i < str1.length)
		{
			(*str) -> ch[i] = str1.ch[i];
			++i;
		}
	int j = 0;
	while(j <= str2.length)
		{
			(*str) -> ch[i+j] = str2.ch[j];
			++j;
		}
	(*str) -> length = str1.length + str2.length;
	return 1;
}

int substring(Str** substr, Str str, int pos, int len)
{
	int LEN = len;
	if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)
		return 0;

	if ((*substr) -> ch)
		{
			free((*substr) -> ch);
			(*substr) -> ch = NULL;
		}

	if (len = 0)
		{
			(*substr) -> ch = NULL;
			(*substr) -> length = 0;
			return 1;
		}
	else
		{
			// printf("len126: %d\n", len), until here len is 0, so why len become to 0?
			((*substr) -> ch) = (char*)malloc(sizeof(char) * len + 1);
			int i = pos;
			int j = 0;
			while(i < pos + LEN)
				{
					(*substr) -> ch[j] = str.ch[i];
					++i;
					++j;
				}
			(*substr) -> ch[j] = '\0';
			(*substr) -> length = len;
			return 1;
		}
}

int clearstring(Str** str)
{
	if ((*str) -> ch)
		{
			free((*str) -> ch);
			(*str) -> ch = NULL;
		}
	(*str) -> length = 0;
	return 1;
}

int main(int argc, char *argv[])
{

	printf("1. test for strassign() function:\n");
	Str* str = (Str*)malloc(sizeof(Str));
	strassign(&str, "this is a assign string");
	printf("%s\n\n", *str);

	printf("2. test for strlength() function:\n");
	printf("the testing string is: '%s', it's length is %d\n\n", *str, strlength(*str));

	printf("3. test for strcompare() function:\n");
	Str* st1 = (Str*)malloc(sizeof(Str));
	Str* st2 = (Str*)malloc(sizeof(Str));
	strassign(&st1, "this is string1");
	strassign(&st2, "this is string2 this is string2");
	printf("st1: %s\n", *st1);
	printf("st2: %s\n", *st2);
	printf("the compare result of st1 and st2: %d\n\n", strcompare(*st1, *st2));

	printf("4. test for concat() function:\n");
	Str* str4 = (Str*)malloc(sizeof(str));
	concat(&str4, *st1, *st2);
	printf("after concat of st1 and st2: %s\n\n", *str4);

	printf("5. test for substring() function:\n");
	Str* substr = (Str*)malloc(sizeof(Str));
	substring(&substr, *st2, 2, 8);
	printf("get 8 chars after third char of st2: %s\n\n", *substr);

	printf("6. test for clearstring() function:\n");
	clearstring(&st2);
	printf("after free of st2: %s\n", *st2);
	
	return 0;
}
