/*
  pqy@sda1:~/.../3_2$ gcc 3_2.c                                                                           
  pqy@sda1:~/.../3_2$ ./a.out 
  All elements:
  34 89 0 1 23 100 
  After left loop move 2 elements:
  0 1 23 100 34 89 
  pqy@sda1:~/.../3_2$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.12 59% Sun 2017-06-18 16:36
*/

#include <stdio.h>

int Reverse(int R[], int l, int r)
{
  int i, j;
  int temp;

  for (i = l, j = r; i < j; ++i, --j)
    {
      temp = R[i];
      R[i] = R[j];
      R[j] = temp;
    }

  return 1;
}


int RCR(int R[], int n, int p)
{
  if (p <= 0 || p >= n)
    printf("ERROR\n");

  else
    {
      Reverse(R, 0, p - 1);
      Reverse(R, p, n - 1);
      Reverse(R, 0, n - 1);
    }

  return 1;
}


int display(int *a, int l)
{
  int i;

  for (i = 0; i <= l - 1; i++)
    printf("%d ", a[i]);

  printf("\n");

  return 1;
}
  

int main(int argc, char *argv[])
{
  int a[6] = {34, 89, 0, 1, 23, 100};

  printf("All elements:\n");
  display(a, 6);

  printf("After left loop move 2 elements:\n");
  RCR(a, 6, 2);
  display(a, 6);
    
  return 0;
}

