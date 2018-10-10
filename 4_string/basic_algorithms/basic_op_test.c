/*
	Test result:
	~/.../example_algorithms$ make
	./test
	1. test for strassign() function:
	this is a assign string

	2. test for strlength() function:
	the testing string is: 'this is a assign string', it's length is 23

	3. test for strcompare() function:
	st1: this is string1
	st2: this is string2 this is string2
	the compare result of st1 and st2: -1

	4. test for concat() function:
	after concat of st1 and st2: this is string1this is string2 this is string2

	5. test for substring() function:
	get 8 chars after third char of st2: is is st

	6. test for clearstring() function:
	after free of st2: (null)
	~/.../example_algorithms$ 
	[pqy7172@debian:0] 0:ss-local 1:bash                                               0.52 100% Sun 2018-10-07 16:23
*/


#include <stdio.h>
#include <stdlib.h>

#include "string_basic_op.c"

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

