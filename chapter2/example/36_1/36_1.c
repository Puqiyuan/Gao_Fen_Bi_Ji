/*
  Test result:
  pqy@sda1:~/.../36_1$ gcc 36_1.c
  pqy@sda1:~/.../36_1$ ./a.out 
  LA:
  2 3 8 11 13 
  LB:
  1 3 9 11 
  After A - B:
  2 8 13 
  pqy@sda1:~/.../36_1$ 
  [pqy@sda1:0]  0:bash 1:bash                                                1.30 36% Sun 2017-06-04 11:3
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int Difference(LNode *A, LNode *B)
{
  LNode *p = A -> next, *q = B -> next;

  LNode *pre = A;

  LNode *r;

  while (p != NULL && q != NULL)
    {
      if (p ->data < q -> data)
	{
	  pre = p;
	  p = p -> next;
	}

      else if (p -> data > q -> data)
	q = q -> next;

      else
	{
	  pre -> next = p -> next;
	  r = p;
	  p = p -> next;
	  free(r);
	}
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
  LNode LA, LB;
  LA.next = NULL;
  LB.next = NULL;
  
  int A[6] = {-1, 2, 3, 8, 11, 13};

  CreatelistR(&LA, A, 5);

  int B[5] = {-1, 1, 3, 9, 11};

  CreatelistR(&LB, B, 4);

  printf("LA:\n");
  display(&LA);

  printf("LB:\n");
  display(&LB);

  Difference(&LA, &LB);
  printf("After A - B:\n");
  display(&LA);
  
  return 1;
}
