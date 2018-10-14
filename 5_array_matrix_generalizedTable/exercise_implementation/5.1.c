/*
	test result:
	~/.../exercise_implementation$ ./a.out 
	input the length of array:8
	input each element of array:
	1 0 0 3 0 1 0 2
	before movement:
	1 0 0 3 0 1 0 2 
	after movement:
	1 3 1 2 0 0 0 0
*/

#include <stdio.h>
#include <stdlib.h>

int movelement(int* A, int n)
{
	int i = -1, j, temp;
	for (j = 0; j < n; ++j)
		{
			if (A[j] != 0)
				{
					++i;
					if (i != j)
						{
							temp = A[i];
							A[i] = A[j];
							A[j] = temp;
						}
				}
		}
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
	printf("before movement:\n");
	for (i = 0; i < n; ++i)
		printf("%d ", A[i]);
	printf("\n");
	movelement(A, n);
	printf("after movement:\n");
	for (i = 0; i < n; ++i)
		printf("%d ", A[i]);
	printf("\n");
	
	return 0;
}

