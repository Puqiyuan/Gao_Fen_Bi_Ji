/*
  Test result:
  pqy@sda1:~/.../28_2$ gcc 28_2.c 
  pqy@sda1:~/.../28_2$ ./a.out 
  All elements:
  34 23 0 1 999 
  The length of the list: 5.
  The return value of item is: 999
  pqy@sda1:~/.../28_2$ 
  [pqy@sda1:0]  0:ss-local 1:less 2:bash                                     1.41 84% Mon 2017-05-15 20:48
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int GetElem(Sqlist L, int p, int *e)
{
  if (p < 1 || p > L.length)
    return 0;

  *e = L.data[p];

  return 1;
}


int display(Sqlist L)
{
  int len = L.length, i;

  for (i = 1; i <= len; i++)
    printf("%d ", L.data[i]);
  printf("\n");

  printf("The length of the list: %d.\n", L.length);
  return 0;
}


int main(int argc, char *argv[])
{
  Sqlist L;

  L.length = 5;

  L.data[1] = 34; L.data[2] = 23; L.data[3] = 0;
  L.data[4] = 1; L.data[5] = 999;

  int *e = (int*)malloc(sizeof(int));

  printf("All elements:\n");

  display(L);

  GetElem(L, 5, e);

  printf("The return value of item is: %d\n", *e);
   
  return 0;
}
