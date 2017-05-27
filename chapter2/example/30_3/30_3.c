/*
  Test result:
  pqy@sda1:~/.../30_3$ gcc 30_3.c
  pqy@sda1:~/.../30_3$ ./a.out 
  Before merge:
  A: 5 5 7 56 
  B: 6 7 101 
  After merge:
  101 56 7 7 6 5 5 
  pqy@sda1:~/.../30_3$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.23 82% Sat 2017-05-27 20:44
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

  LNode *s;

  C -> next = NULL;

  while (p != NULL && q != NULL)
    {
      if (p -> data <= q -> data)
	{
	  s = p; p = p -> next;
	  s -> next = C -> next;
	  C -> next = s;
	}

      else
	{
	  s = q; q = q -> next;
	  s -> next = C -> next;
	  C -> next = s;
	}
    }

  while (p != NULL)
    {
      s = p; p = p -> next;
      s -> next = C -> next;
      C ->next = s;
    }

  while (q != NULL)
    {
      s = q; q = q -> next;
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

  free(A);
  free(B);
  free(C);
    
  return 0;
}

