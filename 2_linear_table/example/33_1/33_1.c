/*
  Test result:
  pqy@sda1:~/.../33_1$ gcc 33_1.c
  pqy@sda1:~/.../33_1$ ./a.out 
  After insert:
  45 12 0 1 101 
  pqy@sda1:~/.../33_1$ 
  [pqy@sda1:0]  0:bash                                                       1.05 95% Sun 2017-06-04 09:30
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct DLNode
{
  int data;

  struct DLNode *prior;
  struct DLNode *next;
}DLNode;


int CreateDlistR(DLNode *L, int *a, int n)
{
  DLNode *s, *r;
  int i;

  r = L;
  for (i = 0; i <= n - 1; i++)
    {
      s = (DLNode*)malloc(sizeof(DLNode));
      s -> data = a[i];
      r -> next = s;
      s -> prior = r;
      r = s;
    }

  r -> next = NULL;

  return 1;
}


int display(DLNode *L)
{
  while (L -> next != NULL)
    {
      printf("%d ", L -> next -> data);
      L = L -> next;
    }

  printf("\n");
  return 1;
}


int main(int argc, char *argv[])
{
  DLNode *L = (DLNode*)malloc(sizeof(DLNode));

  int a[5] = {45, 12, 0, 1, 101};

  CreateDlistR(L, a, 5);

  printf("After insert:\n");
  display(L);
  
  return 1;
}
