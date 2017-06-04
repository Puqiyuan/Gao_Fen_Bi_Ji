/*
  Test result:
  pqy@sda1:~/.../33_1$ gcc 33_2.c
  pqy@sda1:~/.../33_1$ ./a.out 
  After insert:
  45 12 0 1 101 
  Searching the node it's value is 12:
  There is a node in double link list it's value is 12.
  Searching the node it's value is 102:
  Sorry can not find the node it's value is 102.
  pqy@sda1:~/.../33_1$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.44 84% Sun 2017-06-04 09:51
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


DLNode* searchNode(DLNode *C, int x)
{
  DLNode *p = C -> next;

  while (p != NULL)
    {
      if (p -> data == x)
	break;

      p = p -> next;
    }

  return p;
}


int test(DLNode *p, int x)
{
  if (p == NULL)
    printf("Sorry can not find the node it's value is %d.\n", x);

  else
    printf("There is a node in double link list it's value is %d.\n", x);

  return 1;
}


int main(int argc, char *argv[])
{
  DLNode *L = (DLNode*)malloc(sizeof(DLNode));

  int a[5] = {45, 12, 0, 1, 101};

  CreateDlistR(L, a, 5);

  printf("After insert:\n");
  display(L);
  
  DLNode *p = (DLNode*)malloc(sizeof(DLNode));

  printf("Searching the node it's value is 12:\n");
  p = searchNode(L, 12);
  test(p, 12);

  printf("Searching the node it's value is 102:\n");
  p = searchNode(L, 102);
  test(p, 102);
  
  return 1;
}

