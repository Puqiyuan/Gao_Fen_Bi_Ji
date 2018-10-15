/*
	test result:
	~/.../exercise_implementation$ ./a.out 
	input the length of array:8
	input each element of array:
	1 0 0 3 0 1 0 2
	the maximum of the array: 3.00
	the sum of the array: 7.00
	the average of the array: 0.88
 */

#include <stdio.h>
#include <stdlib.h>

float findmax(float* A, int i, int j)
{
	float max;
	if (i == j)
		return A[i];
	else
		{
			max = findmax(A, i + 1, j);
			if (A[i] > max)
				return A[i];
			else
				return max;
		}
}

float arraysum(float* A, int i, int j)
{
	if (i == j)
		return A[i];
	else
		return A[i] + arraysum(A, i + 1, j);
}

float arrayavg(float* A, int i, int j)
{
	if (i == j)
		return A[i];
	else
		return (A[i] + (j - i) * arrayavg(A, i + 1, j)) / (j - i + 1);
}

int main(int argc, char *argv[])
{
	int n, i;
  printf("input the length of array:");
  scanf("%d", &n);

  float* A = (float*)malloc(n * sizeof(float));
  printf("input each element of array:\n");
  for (i = 0; i < n; ++i)
    scanf("%f", &A[i]);

	printf("the maximum of the array: %.2f\n", findmax(A, 0, n - 1));
	printf("the sum of the array: %.2f\n", arraysum(A, 0, n - 1));
	printf("the average of the array: %.2f\n", arrayavg(A, 0, n - 1));
	
	return 0;
}
