/*
  Test result:
  pqy@sda1:~/.../34_2$ gcc 34_2.c
  pqy@sda1:~/.../34_2$ ./a.out 
  After created double link list:
  45 12 0 1 101 
  Searching the node it's value is 12:
  There is a node in double link list it's value is 12.
  After delete the successor of node 12:
  45 12 1 101 
  pqy@sda1:~/.../34_2$ 
  [pqy@sda1:0]  0:bash 1:less                                                1.16 62% Sun 2017-06-04 10:37
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


int Delete(DLNode *p)
{

  DLNode *q = (DLNode*)malloc(sizeof(DLNode));
  
  if (p != NULL)
    {
      q = p -> next;
      p ->next = q -> next;
      q -> next -> prior = p;
      free(q);
    }

  else
    return 0;

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

  printf("After delete the successor of node 12:\n");
  Delete(p);
  
  display(L);

  return 1;
}
