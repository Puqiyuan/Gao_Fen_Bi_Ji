/*
  Test result:
  pqy@sda1:~/.../2_3$ gcc 2_3.c
  pqy@sda1:~/.../2_3$ ./a.out 
  All elements:
  1 2 3 4 
  The max is 4, min is 1.
  pqy@sda1:~/.../2_3$ 
  [pqy@sda1:0]  0:ss-local 1:bash                                           1.58 100% Wed 2017-06-07 22:56
 */

#include <stdio.h>
#include <stdlib.h>


int FindMaxMin(int A[], int n, int *max, int *min)
{
  *max = *min = A[1];
  int i;

  for (i = 2; i <= n; ++i)
    {
      if (A[i] > *max)
	*max = A[i];
      
      else if (A[i] < *min)
	*min = A[i];
    }

  return 1;
}


int display(int *A, int n)
{
  int i = 1;

  for (i = 1; i <= n; i++)
    printf("%d ", A[i]);

  printf("\n");

  return 1;
}
  


int main(int argc, char *argv[])
{
  int *min = (int*)malloc(sizeof(int)), *max = (int*)malloc(sizeof(int)), A[5] = {-1, 1, 2, 3, 4};
  //0 index is not used.

  printf("All elements:\n");
  display(A, 4);
  
  FindMaxMin(A, 4, max, min);

  printf("The max is %d, min is %d.\n", *max, *min);
  
  return 0;
}




