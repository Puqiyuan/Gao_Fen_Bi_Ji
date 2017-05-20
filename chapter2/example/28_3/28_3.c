/*
  pqy@sda1:~/.../28_3$ gcc 28_3.c                                                                         
  pqy@sda1:~/.../28_3$ ./a.out                                                                            
  Before merge:
  A: 5 5 7 56 
  B: 6 7 101 
  After merge:
  5 5 6 7 7 56 101 
  pqy@sda1:~/.../28_3$ 
  [pqy@sda1:0]  0:ss-local 1:less 2:bash                                    1.00 100% Sat 2017-05-20 22:13
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int merge(LNode *A, LNode *B, LNode *C)
{
  LNode *p = A -> next;
  LNode *q = B -> next;

  LNode *r;

  C -> next = A;

  C -> next = NULL;
  r = C;

  while (p != NULL && q != NULL)
    {
      if (p -> data <= q -> data)
	{
	  r -> next = p; p = p -> next;
	  r = r -> next;
	}

      else
	{
	  r -> next = q; q = q ->next;
	  r = r -> next;
	}
    }

  r -> next = NULL;

  if (p != NULL)
    r -> next = p;

  if (q != NULL)
    r -> next = q;

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
  LNode *A = (LNode*)malloc(sizeof(LNode));
  LNode *B = (LNode*)malloc(sizeof(LNode));
  LNode *C = (LNode*)malloc(sizeof(LNode));

  LNode a1, a2, a3, a4;
  a1.data = 5; a1.next = &a2;
  a2.data = 5; a2.next = &a3;
  a3.data = 7; a3.next = &a4;
  a4.data = 56; a4.next = NULL;

  A -> next = &a1;
  
  LNode b1, b2, b3;
  b1.data = 6; b1.next = &b2;
  b2.data = 7; b2.next = &b3;
  b3.data = 101; b3.next = NULL;

  B -> next = &b1;

  printf("Before merge:\n");
  printf("A: ");
  display(A);
  printf("B: ");
  display(B);

  printf("After merge:\n");
  merge(A, B, C);
  display(C);
    
  return 0;
}
