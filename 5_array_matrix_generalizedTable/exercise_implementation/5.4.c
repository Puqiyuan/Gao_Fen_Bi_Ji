/*
	running results:
	~/.../exercise_implementation$ ./a.out 
	input the length of array:8
	input each element of array:
	49 38 65 97 76 13 27 49
	27 38 13 49 76 97 65 49
*/

#include <stdio.h>
#include <stdlib.h>

int QuickSort(int* arr, int low, int high)
{
	int temp;
	int i = low, j = high;
	if (low < high)
		{
			temp = arr[low];

			while (i < j)
				{
					while (j > i && arr[j] >= temp) --j;
					if (i < j)
						{
							arr[i] = arr[j];
							++i;
						}
					while (i < j && arr[i] < temp) ++i;
					if (i < j)
						{
							arr[j] = arr[i];
							--j;
						}
				}
			arr[i] = temp;
			//QuickSort(arr, low, i-1);
			//QuickSort(arr, i+1, high);
		}
}

int main(int argc, char *argv[])
{
	int n, i;
  printf("input the length of array:");
  scanf("%d", &n);

  int* arr = (int*)malloc(n * sizeof(int));
  printf("input each element of array:\n");
  for (i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

	QuickSort(arr, 0, n-1);
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}

