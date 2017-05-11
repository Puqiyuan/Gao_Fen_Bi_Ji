/*
  Test result:

  pqy@sda1:~/.../27_1$ gcc 27_1.c 
pqy@sda1:~/.../27_1$ ./a.out 
All elements:
34 23 0 1 999 
The length of the list: 5.
23 is in: 2.
19 is in: -1.
 */

#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
  int data[maxSize];

  int length;
}Sqlist;


int LocateElem (Sqlist L, int e)
{
  int i;

  for (i = 1; i <= L.length; ++i)
    {
      if (e == L.data[i])
	return i; 
    }

  return -1;
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

  printf("All elements:\n");
  display(L);

  printf("23 is in: %d.\n", LocateElem(L, 23));

  printf("19 is in: %d.\n", LocateElem(L, 19));
  
  return 0;
}
