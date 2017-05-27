/*
  Test result:
  pqy@sda1:~/.../32_1$ gcc 32_1.c 
  pqy@sda1:~/.../32_1$ ./a.out 
  Before search and delete:
  A: 5 5 7 56 
  After search and delete 100:
  A: 5 5 7 56 
  After search and delete 7:
  A: 5 5 56 
  pqy@sda1:~/.../32_1$ 
  [pqy@sda1:0]  0:ss-local 1:bash                                            1.81 78% Sat 2017-05-27 21:27
 */



#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int SearchAndDelete(LNode *C, int x)
{
  LNode *p;

  p = C;

  while (p -> next != NULL)
    {
      if (p -> next -> data == x)
	break;

      p = p -> next;
    }

  if (p -> next == NULL)
    return 0;

  else
    {
      p -> next = p -> next -> next;
      
      return 1;
    }
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

  LNode a1, a2, a3, a4;
  a1.data = 5; a1.next = &a2;
  a2.data = 5; a2.next = &a3;
  a3.data = 7; a3.next = &a4;
  a4.data = 56; a4.next = NULL;

  A -> next = &a1;

  printf("Before search and delete:\n");
  printf("A: ");
  display(A);

  printf("After search and delete 100:\n");
  SearchAndDelete(A, 100);
  printf("A: ");
  display(A);
  printf("After search and delete 7:\n");
  SearchAndDelete(A, 7);
  printf("A: ");
  display(A);

  return 1;
}
   
  



