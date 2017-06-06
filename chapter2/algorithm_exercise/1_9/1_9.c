/*
  Test result:
  pqy@sda1:~/.../1_9$ gcc 1_9.c
  pqy@sda1:~/.../1_9$ ./a.out 
  Before parting, C:
  1 2 3 4 6 
  After parted, C:
  1 3 
  B:
  2 4 6 
  pqy@sda1:~/.../1_9$ 
  [pqy@sda1:0]  0:ss-local 1:mplayer 2:bash                                 1.30 100% Tue 2017-06-06 23:18
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int split2(LNode *A, LNode *B)
{
  LNode *p, *q, *r;

  r = B;
  p = A;

  while(p -> next != NULL)
    {
      if (p -> next -> data % 2 == 0)
	{
	  q = p -> next;
	  p -> next = q -> next;//overwrite
	  q -> next = NULL;
	  r -> next = q;
	  r = q;
	}

      else
	p = p -> next;
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
  printf("Before parting, C:\n");
  display(&C);

  LNode B;

  B.next = NULL;

  split2(&C, &B);
  printf("After parted, C:\n");
  display(&C);
  printf("B:\n");
  display(&B);
  
  return 0;
}

