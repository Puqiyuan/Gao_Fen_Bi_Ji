/*
  Test result:
  pqy@sda1:~/.../35_1$ gcc 35_1.c
  pqy@sda1:~/.../35_1$ ./a.out 
  Before sorted:
  2 3 9 11 5 10 
  After sorted:
  2 3 5 9 10 11 
  pqy@sda1:~/.../35_1$ 
  [pqy@sda1:0]  0:bash 1:less                                                1.03 50% Sun 2017-06-04 11:03
 */

#include <stdio.h>

int Insert(int A[], int m, int n)
{
  int i, j;

  int temp;

  for (i = m + 1; i <= m + n; ++i)
    {
      temp = A[i];

      for (j = i - 1; j >= 1 && temp < A[j]; --j)
	A[j + 1] = A[j];

      A[j + 1] = temp;
    }

  return 1;
}


int display(int A[], int L)
{
  int i;

  for (i = 1; i <= L; i++)
    printf("%d ", A[i]);

  printf("\n");

  return 1;
}


int main(int argc, char *argv[])
{
  int A[7] = {-1, 2, 3, 9, 11, 5, 10};

  printf("Before sorted:\n");
  display(A, 6);

  Insert(A, 4, 2);

  printf("After sorted:\n");
  display(A, 6);
    
  return 0;
}
