/*
  Test result:
  pqy@sda1:~/.../1_5$ gcc 1_5.c
  pqy@sda1:~/.../1_5$ ./a.out 
  Before move:
  2 1 -7 -3 5 6 -1 
  The length of the list: 7.
  After move:
  -1 1 -7 -3 2 6 5 
  The length of the list: 7.
 */


#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int move(Sqlist *L)
{
  int temp;
  int i = 0, j = L->length - 1;

  temp = L->data[i];

  while (i < j)
    {
      while (i < j && L->data[j] > temp) --j;

      if (i < j)
	{
	  L->data[i] = L->data[j];
	  ++i;
	}

      while (i < j && L->data[i] < temp) ++i;

      if (i < j)
	{
	  L->data[j] = L->data[i];
	  --j;
	}
    }

  L->data[i] = temp;
  
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

  L.length = 7;

  L.data[0] = 2; L.data[1] = 1; L.data[2] = -7;
  L.data[3] = -3; L.data[4] = 5; L.data[5] = 6;
  L.data[6] = -1;

  printf("Before move:\n");
  display(L);

  printf("After move:\n");
  move(&L);
  display(L);
  
  return 0;
}

