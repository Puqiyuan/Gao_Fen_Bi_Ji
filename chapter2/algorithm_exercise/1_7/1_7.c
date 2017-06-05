/*
  Test result:
  pqy@sda1:~/.../1_7$ gcc 1_7.c
  pqy@sda1:~/.../1_7$ ./a.out 
  Before delete minimum:
  1 2 3 5 
  After delete the minimum:
  2 3 5 
  pqy@sda1:~/.../1_7$ 
  [pqy@sda1:0]  0:ss-local 1:mplayer 2:1_6_1.c 3:bash                        1.45 99% Mon 2017-06-05 23:31
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct LNode
{
  int data;
  struct LNode *next;
}LNode;


int delminnode(LNode *L)
{
  LNode *pre = L, *p = pre -> next, *minp = p, *minpre = pre;

  while (p != NULL)
    {
      if (p -> data < minp -> data)
	{
	  minp = p;
	  minpre = pre;
	}

      pre = p;
      p = p -> next;
    }

  minpre -> next = minp -> next;
  free(minp);

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
  int a[5] = {-1, 1, 2, 3, 5};

  LNode C;

  C.next = NULL;

  CreatelistR(&C, a, 4);

  printf("Before delete minimum:\n");
  display(&C);

  delminnode(&C);

  printf("After delete the minimum:\n");
  display(&C);
  
  return 0;
}
