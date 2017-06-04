/*
  Test result:
  pqy@sda1:~/.../34_1$ gcc 34_1.c
  pqy@sda1:~/.../34_1$ ./a.out 
  After created double link list:
  45 12 0 1 101 
  Searching the node it's value is 12:
  There is a node in double link list it's value is 12.
  Inserted a node it's value is 477 after the node it's value is 12:
  45 12 477 0 1 101 
  pqy@sda1:~/.../34_1$ 
  [pqy@sda1:0]  0:bash 1:less                                                1.30 74% Sun 2017-06-04 10:15
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


int Insert(DLNode *s, DLNode *p)
{
  s -> next = p -> next;
  s -> prior = p;
  p -> next = s;
  s -> next -> prior = s;

  return 1;
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

  printf("After created double link list:\n");
  display(L);
  
  DLNode *p = (DLNode*)malloc(sizeof(DLNode));

  printf("Searching the node it's value is 12:\n");
  p = searchNode(L, 12);
  test(p, 12);

  DLNode *s = (DLNode*)malloc(sizeof(DLNode));
  
  s -> data = 477;
  
  Insert(s, p);

  printf("Inserted a node it's value is %d after the node it's value is %d:\n",
	 s -> data, p -> data);

  display(L);

  return 1;
}
