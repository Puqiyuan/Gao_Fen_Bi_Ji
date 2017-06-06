/*
  Test result:
  pqy@sda1:~/.../1_8$ gcc 1_8.c
  pqy@sda1:~/.../1_8$ ./a.out 
  Before reverse:
  1 2 3 5 
  After reverse:
  5 3 2 1 
  pqy@sda1:~/.../1_8$ 
  [pqy@sda1:0]  0:ss-local 1:mplayer 2:bash                                 1.14 100% Tue 2017-06-06 22:43
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int Reversel(LNode *L)
{
  LNode *p = L -> next, *q;

  L -> next = NULL;

  while (p != NULL)
    {
      q = p -> next;
      p -> next = L -> next;
      L -> next = p;
      p = q;
    }

  return 1;
}


int CreatelistR(LNode *C, int *a, int n)
{
  LNode *s, *r = (LNode*)malloc(sizeof(LNode));
  int i;

  r = C;
  for (i = 1; i <= n; i++)
    {
      s = (LNode*)malloc(sizeof(LNode));
      s -> data = a[i];
      r -> next = s;
      r = r -> next;
    }

  r -> next = NULL;

  return 1;
}


int display(LNode *L)
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
  int a[5] = {-1, 1, 2, 3, 5};

  LNode C;

  C.next = NULL;

  CreatelistR(&C, a, 4);
  printf("Before reverse:\n");
  display(&C);

  Reversel(&C);
  printf("After reverse:\n");
  display(&C);
  
  return 0;
}

