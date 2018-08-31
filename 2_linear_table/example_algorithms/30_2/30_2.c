/*
  Test result:
  pqy@sda1:~/.../30_2$ gcc 30_2.c
  pqy@sda1:~/.../30_2$ ./a.out                                                                            
  Before insert:
  34 78 1 -1245 9 
  After insert:
  9 -1245 1 78 34 
  pqy@sda1:~/.../30_2$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.15 92% Sat 2017-05-27 20:21
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int CreatelistF(LNode *C, int *a, int n)
{
  LNode *s;
  int i;

  for (i = 1; i <= n; i++)
    {
      s = (LNode*)malloc(sizeof(LNode));
      s -> data = a[i];
      s -> next = C -> next;
      C -> next = s;
    }

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

  CreatelistF(&C, a, 5);

  printf("After insert:\n");
  display(&C);
  
  return 0;
}
