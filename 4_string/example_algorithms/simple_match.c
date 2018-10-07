#include <stdio.h>
#include "./string_basic_op.c"

int Index(Str str, Str substr)//can't use index, it's reserved.
{
	int i = 0, j = 0, k = i;
	while (i < str.length && j < substr.length)
		{
			if (str.ch[i] == substr.ch[j])
				{
					++i;
					++j;
				}
			else
				{
					j = 1;
					i = ++k;
				}
		}
	if (j == substr.length)
		return k;

	return 0;
}

int main(int argc, char *argv[])
{
	Str* str = (Str*)malloc(sizeof(Str));
	Str* substr = (Str*)malloc(sizeof(Str));
	
	strassign(&str, "ABABCABCACBAB");
	strassign(&substr, "ABCAC");

	printf("main string: %s\n", *str);
	printf("pattern string: %s\n", *substr);
	printf("the matching index in str is %d\n", Index(*str, *substr));
	
	return 0;
}

