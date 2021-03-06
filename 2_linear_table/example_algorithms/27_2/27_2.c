/*
  Test result:
  pqy@sda1:~/.../27_2$ gcc 27_2.c 
  pqy@sda1:~/.../27_2$ ./a.out 
  All elements before insert:
  34 23 0 1 999 
  The length of the list: 5.
  All elements after insert:
  34 101 23 0 1 999 
  The length of the list: 6.
  pqy@sda1:~/.../27_2$ 
  [pqy@sda1:0]  0:ss-local 1:less 2:bash                                     1.39 93% Mon 2017-05-15 20:2
 */


#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int insert(Sqlist *L, int p, int e)
{
  int i;

  if (p < 1 || p > L->length + 1 || L->length == maxSize - 1)
    return 0;

  for (i = L->length; i >= p; --i)
    L->data[i + 1] = L->data[i];

  L->data[p] = e;
  ++(L->length);

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

  printf("All elements before insert:\n");
  display(L);

  insert(&L, 2, 101);
  printf("All elements after insert:\n");
  display(L);
  
  return 0;
}
