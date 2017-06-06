/*
  Test result:
  pqy@sda1:~/.../2_1$ gcc 2_1.c
  pqy@sda1:~/.../2_1$ ./a.out 
  The minimum is 2.
  pqy@sda1:~/.../2_1$ 
  [pqy@sda1:0]  0:ss-local 1:mplayer 2:bash                                  1.90 89% Tue 2017-06-06 23:48
 */
#include <stdio.h>
#define N 5


int FindMin(int *A, int *i)
{
  *i = A[0];

  while(*i / 10 <= N - 1)
    {
      if (*i % 10 > A[*i / 10])
	{
	  *i = *i - *i % 10;
	  *i = *i + A[*i / 10];
	  *i = *i + 10;
	}
      *i = *i + 10;
    }

  *i = *i % 10;

  return 1;
}


int main(int argc, char *argv[])
{
  int A[5] = {5, 8, 2, 4, 9};
  int i;

  FindMin(A, &i);
  printf("The minimum is %d.\n", i);
  
  return 0;
}

