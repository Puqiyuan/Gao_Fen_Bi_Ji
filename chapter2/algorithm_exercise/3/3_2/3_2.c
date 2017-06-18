#include <stdio.h>

int Reverse(int R[], int l, int r)
{
  int i, j;
  int temp;

  for (i = l; j = r; i < j; ++i; --j)
    {
      temp = R[i];
      R[i] = R[j];
      R[j] = temp;
    }

  return 1;
}
