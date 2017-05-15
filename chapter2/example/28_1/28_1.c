#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int InitList(Sqlist *L)
{
  L->length = 0;
}


