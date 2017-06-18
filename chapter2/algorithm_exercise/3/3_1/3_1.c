/*
  pqy@sda1:~/.../3_1$ gcc 3_1.c 
  pqy@sda1:~/.../3_1$ ./a.out 
  All elements:
  1 2 3 4 6 
  The last element:
  6
  The second element in reverse order:
  4
  The sixth element in reverse order:
  Sorry, there is no element which you want.
  pqy@sda1:~/.../3_1$ 
  [pqy@sda1:0]  0:less 1:bash                                                1.31 69% Sun 2017-06-18 16:12
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int LocateElement(LNode *head, int k)
{
  LNode *p1, *p;
  p1 = head -> next;
  p = head;
  int i = 1;

  while (p1)
    {
      p1 = p1 -> next;
      i++;
      if (i > k)
	p = p -> next;
    }

  if (p == head)
    {
      printf("Sorry, there is no element which you want.\n");
      return 0;
    }

  else
    printf("%d\n", p -> data);
  
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
      printf("%d ", L -> next ->data);
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
  printf("All elements:\n");
  display(&C);
  
  printf("The last element:\n");
  LocateElement(&C, 1);

  printf("The second element in reverse order:\n");
  LocateElement(&C, 2);

  printf("The sixth element in reverse order:\n");
  LocateElement(&C, 6);
  
  return 0;
}
