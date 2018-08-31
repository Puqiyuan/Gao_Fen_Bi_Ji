/*
  Test result:

  pqy@sda1:~/.../example$ gcc p25_1.c 
  pqy@sda1:~/.../example$ ./a.out 
  Before insert: 
  4 5 7 9 10 13 7 21 
  After insert: 
  4 5 7 9 10 12 13 7 21 
  pqy@sda1:~/.../example$
  
  [pqy@sda1:0]  0:ss-local 1:bash 2:bash                                     1.24 72% Tue 2017-05-09 21:17
 */


#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int LocateElem(Sqlist L, int x)
{
  int i;

  for (i = 1; i <= L.length; ++i)
    {
      if (x < L.data[i])
	{
	  return i;
	}
    }

  return i;
}


int insert(Sqlist *L, int x)
{
  int p, i;

  p = LocateElem(*L, x);

  for (i = L->length; i >= p; --i)
    L->data[i + 1] = L->data[i];

  L->data[p] = x;
  ++(L->length);

  return 1;
}


int display(Sqlist L)
{
  int len = L.length, i;

  for (i = 1; i <= len; i++)
    printf("%d ", L.data[i]);
  printf("\n");

  return 0;
}


int main(int argc, char *argv[])
{
  Sqlist L;
  int x = 12;

  L.length = 8;

  L.data[1] = 4; L.data[2] = 5;
  L.data[3] = 7; L.data[4] = 9;
  L.data[5] = 10; L.data[6] = 13;
  L.data[7] = 7; L.data[8] = 21;

  printf("Before insert: \n");
  display(L);

  printf("After insert: \n");
  insert(&L, x);
  display(L);
  
  return 0;
}
