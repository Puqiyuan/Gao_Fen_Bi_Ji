/*
  Test result:
  pqy@sda1:~/.../1_3$ gcc 1_3.c
  pqy@sda1:~/.../1_3$ ./a.out 
  Before reverse:
  34 23 0 1 999 
  After reverse:
  999 1 0 23 34
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int reverse(Sqlist *L)
{
  int i, j;//The i start from the first data item, and j start from the last data item, swap the
  // value that pointed by i and j.
  int tmp;

  for (i = 0, j = L->length - 1; i < j; ++i, --j)
    {
      tmp = L->data[i];
      L->data[i] = L->data[j];
      L->data[j] = tmp;
    }

  return 0;
}


int display(Sqlist L)
{
  int len = L.length, i;

  for (i = 0; i <= len - 1; i++)
    printf("%d ", L.data[i]);
  printf("\n");

  return 0;
}


int main(int argc, char *argv[])
{
  Sqlist L;

  L.length = 5;

  L.data[0] = 34; L.data[1] = 23; L.data[2] = 0;
  L.data[3] = 1; L.data[4] = 999;

  printf("Before reverse:\n");
  display(L);

  printf("After reverse:\n");
  reverse(&L);
  display(L);
  
  return 0;
}

