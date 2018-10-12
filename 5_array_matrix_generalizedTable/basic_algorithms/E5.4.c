#include <stdio.h>
#include <stdlib.h>

int createtrimat(float** A, int m, int n, float** B)
{
	int k = 1;
	for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				{
					if (A[i][j] != 0)
						{
							B[k][0] = A[i][j];
							B[k][1] = i;
							B[k][2] = j;
							++k;
						}
				}
		}
	B[0][0] = k - 1;
	B[0][1] = m;
	B[0][2] = n;
	
	return 0;
}

int print(float** B)
{
	int k = 1;
	for (int i = 0; i < B[0][1]; ++i)
		{
			for (int j = 0; j < B[0][2]; ++j)
				{
					if (i == (int)B[k][1] && j == (int)B[k][2])
						{
							printf("%.2f \n", B[k][0]);
							++k;
						}
					else
						printf("0 ");
				}
		}
}

int main(int argc, char *argv[])
{
	int m, n, i, j;
	printf("input the rows and lines of float array:");
	scanf("%d %d", &m, &n);

	float** A = (float**)malloc(m * sizeof(float*));
	for (i = 0; i < m; ++i)
		A[i] = (float*)malloc(n * sizeof(float));

	float** B = (float**)malloc((m + 1) * sizeof(float*));
	for (i = 0; i < m + 1; ++i)
		B[i] = (float*)malloc(3 * sizeof(float));
				
	printf("input each element of array:\n");
	for (i = 0; i <= m - 1; ++i)
		for (j = 0; j <= n - 1; ++j)
			scanf("%f", &A[i][j]);

	createtrimat(A, m, n, B);
	//	print(B);
	
	return 0;
}
