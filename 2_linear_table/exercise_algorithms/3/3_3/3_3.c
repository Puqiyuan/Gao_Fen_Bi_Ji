/*
  Test result1:
  pqy@sda1:~/.../3_3$ gcc 3_3.c 
  pqy@sda1:~/.../3_3$ ./a.out 
  All elements:
  0 2 2 3 2 7 2 2 
  The main element is: 2.
  pqy@sda1:~/.../3_3$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.16 37% Sun 2017-06-18 17:20

  Test result2:
  pqy@sda1:~/.../3_3$ gcc 3_3.c 
  pqy@sda1:~/.../3_3$ ./a.out 
  All elements:
  0 5 5 3 5 1 5 7 
  There is no main element.
  pqy@sda1:~/.../3_3$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.32 36% Sun 2017-06-18 17:22
*/

#include <stdio.h>
#include <stdlib.h>

int count(int *in, int *c_er, int len)
{
  int i;

  for (i = 0; i <= len - 1; i++)
    (c_er[in[i]])++;

  return 1;
}


int judge(int *c_er, int len, int *val)
{
  int max = c_er[0], i;
  *val = 0;

  for (i = 1; i <= len - 1; i++)
    {
      if (c_er[i] > max)
	{
	  max = c_er[i];
	  *val = i;
	}
    }

  if (max > (len / 2))
    return 1;

  return 0;
}


int display(int *a, int len)
{
  int i;

  for (i = 0; i <= len - 1; i++)
    printf("%d ", a[i]);

  printf("\n");

  return 1;
}


int main(int argc, char *argv[])
{
  int a[8] = {0, 5, 5, 3, 5, 1, 5, 7};
  int *c_er = (int*)malloc(8 * sizeof(int));
  int *val = (int*)malloc(sizeof(int));

  printf("All elements:\n");
  display(a, 8);
  
  count(a, c_er, 8);

  if (judge(c_er, 8, val) == 1)
    printf("The main element is: %d.\n", *val);

  else
    printf("There is no main element.\n");
    
  return 0;
}
