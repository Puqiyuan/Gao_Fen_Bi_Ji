/*
  test result:
  pqy@sda1:~/.../29_1$ gcc 29_1.c 
  pqy@sda1:~/.../29_1$ ./a.out 
  Before insert:
  34 78 1 -1245 9 
  After insert:
  34 78 1 -1245 9 
  pqy@sda1:~/.../29_1$ 
  [pqy@sda1:0]  0:29_1.c 1:bash 2:28_3.c                                     1.36 43% Tue 2017-05-23 21:32
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


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
  int a[6], i;
  a[1] = 34;  a[2] = 78;
  a[3] = 1;  a[4] = -1245;
  a[5] = 9;
  
  LNode C;

  C.next = NULL;

  printf("Before insert:\n");
  for (i = 1; i <= 5; i++)
    printf("%d ", a[i]);

  printf("\n");

  CreatelistR(&C, a, 5);

  printf("After insert:\n");
  display(&C);
  
  return 0;
}
