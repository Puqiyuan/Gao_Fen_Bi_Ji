/*
  Test result1:
  pqy@sda1:~/.../2_4$ gcc 2_4.c
  pqy@sda1:~/.../2_4$ ./a.out 
  A is:
  2 4 5 9 
  B is:
  2 5 5 9 
  A less than B.
  pqy@sda1:~/.../2_4$ 
  [pqy@sda1:0]  0:bash                                                       2.32 85% Sun 2017-06-11 10:30

  Test result2:
  pqy@sda1:~/.../2_4$ gcc 2_4.c
  pqy@sda1:~/.../2_4$ ./a.out 
  A is:
  2 4 5 9 
  B is:
  2 4 5 9 
  A equal to B.
  pqy@sda1:~/.../2_4$ 
  [pqy@sda1:0]  0:bash                                                       2.17 83% Sun 2017-06-11 10:32

  Test result3:
  pqy@sda1:~/.../2_4$ gcc 2_4.c
  pqy@sda1:~/.../2_4$ ./a.out 
  A is:
  2 5 5 9 
  B is:
  2 4 5 9 
  A larger than B.
  pqy@sda1:~/.../2_4$ 
  [pqy@sda1:0]  0:bash                                                       2.17 83% Sun 2017-06-11 10:33
*/

#include <stdio.h>
#include <math.h>
#define min 0


int Compare(int A[], int An, int B[], int Bn)
{
  int i = 1;

  while (i <= An && i <= Bn)
    {
      if (fabs(A[i] - B[i]) <= min)
	++i;
      else
	break;
    }

  if (i > An && i > Bn)
    return 0;

  else if ((i > An && i < Bn) || A[i] < B[i])
    return -1;
  
  return 1;
}


int display(int *A, int n)
{
  int i;

  for (i = 1; i <= n; i++)
    printf("%d ", A[i]);

  printf("\n");

  return 1;
}


int main(int argc, char *argv[])
{
  int A[5] = {-1, 2, 5, 5, 9};
  int B[5] = {-1, 2, 4, 5, 9};

  int res = Compare(A, 4, B, 4);

  printf("A is:\n");
  display(A, 4);
  printf("B is:\n");
  display(B, 4);
    
  if (res == 0)
    printf("A equal to B.\n");

  else if (res == -1)
    printf("A less than B.\n");

  else
    printf("A larger than B.\n");
      
  return 0;
}

