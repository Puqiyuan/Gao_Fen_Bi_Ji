/*
  Test result:
  pqy@sda1:~/.../1_6$ gcc 1_6_2.c
  pqy@sda1:~/.../1_6$ ./a.out 
  Before delete:
  1 1 1 2 2 3 3 3 3 5 5 
  After delete repeated data:
  1 2 3 5 
  pqy@sda1:~/.../1_6$ 
  [pqy@sda1:0]  0:ss-local 1:mplayer 2:1_6_1.c 3:bash                       1.16 100% Mon 2017-06-05 23:10
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int delsl2(LNode *L)
{
  LNode *p = L -> next, *q = L -> next -> next, *r;

  while (q != NULL)
    {
      while (q != NULL && q -> data == p -> data)
	q = q -> next;

      if (q != NULL)
	{
	  p = p -> next;
	  p -> data = q -> data;
	}
    }

  q = p -> next;
  p -> next = NULL;

  while (q != NULL)
    {
      r = q;
      q = q -> next;
      free(r);
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
  int a[12] = {-1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 5, 5};

  LNode C;

  C.next = NULL;

  CreatelistR(&C, a, 11);

  printf("Before delete:\n");
  display(&C);

  delsl2(&C);

  printf("After delete repeated data:\n");
  display(&C);
  
  return 0;
}
