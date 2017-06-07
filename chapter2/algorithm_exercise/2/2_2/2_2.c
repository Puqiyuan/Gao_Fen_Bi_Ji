/*
  Test result:
  pqy@sda1:~/.../2_2$ gcc 2_2.c
  pqy@sda1:~/.../2_2$ ./a.out 
  Print as normal:
  1 2 3 4 6 
  Print as reverse:
  6 4 3 2 1 
  pqy@sda1:~/.../2_2$ 
  [pqy@sda1:0]  0:ss-local 1:bash                                           1.13 100% Wed 2017-06-07 22:37
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int reprint(LNode *L)
{
  if (L != NULL)
    {
      reprint(L -> next);
      if (L -> data != 0)
	printf("%d ", L -> data);
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
  int a[6] = {-1, 1, 2, 3, 4, 6};

  LNode C;

  C.next = NULL;

  CreatelistR(&C, a, 5);
  printf("Print as normal:\n");
  display(&C);

  printf("Print as reverse:\n");
  reprint(&C);

  printf("\n");
    
  return 0;
}

