/*
  Test result:
  
  pqy@sda1:~/.../1_4$ gcc 1_4.c
  pqy@sda1:~/.../1_4$ ./a.out 
  Before delete:
  34 23 0 1 999 
  The length of the list: 5.
  After delete:
  34 999 
  The length of the list: 2.
 */


#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int delete(Sqlist *L, int i, int j)//note that when you count the start point is 0.
{
  int k, l;

  l = j - i + 1;

  for (k = j + 1; k <= L->length; ++k)
    L->data[k - l] = L->data[k];

  L->length -= l;

  return 0;
}


int display(Sqlist L)
{
  int len = L.length, i;

  for (i = 0; i <= len - 1; i++)
    printf("%d ", L.data[i]);
  printf("\n");

  printf("The length of the list: %d.\n", L.length);
  return 0;
}


int main(int argc, char *argv[])
{
  Sqlist L;

  L.length = 5;

  L.data[0] = 34; L.data[1] = 23; L.data[2] = 0;
  L.data[3] = 1; L.data[4] = 999;

  printf("Before delete:\n");
  display(L);

  printf("After delete:\n");
  delete(&L, 1, 3);
  display(L);
  
  return 0;
}
