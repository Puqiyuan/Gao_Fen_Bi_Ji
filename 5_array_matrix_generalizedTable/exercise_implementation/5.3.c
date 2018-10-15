/*
	running result:
	~/.../exercise_implementation$ ./a.out 
	input the length of array:6
	input each element of array:
	3 4 2 1 5 6
	after movement:
	3 5 1 2 4 6
*/

#include <stdio.h>
#include <stdlib.h>

int divide(int* A, int n)
{
	int i = 0, j = n - 1, temp;
	while (i < j)
		{
			while (A[i] % 2 == 1 && i < j)
				++i;
			while (A[j] % 2 == 0 && i < j)
				--j;
			if (i < j)
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
					++i;
					--j;
				}
		}
	
	return 0;
}

int main(int argc, char *argv[])
{
	int n, i;
  printf("input the length of array:");
  scanf("%d", &n);

	int* A = (int*)malloc(n * sizeof(int));
	printf("input each element of array:\n");
	for (i = 0; i < n; ++i)
    scanf("%d", &A[i]);

	divide(A, n);
	printf("after movement:\n");
	for (i = 0; i < n; ++i)
		printf("%d ", A[i]);
	printf("\n");
	
	return 0;
}

