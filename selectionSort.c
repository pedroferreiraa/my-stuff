#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Simple implementation of selection sort algorithm. */

void printArray(int arr_count, int *arr)
{
	for (int i = 0; i < arr_count; ++i)
		printf("%d ", arr[i]);
	printf("\n");

}

int* selectionSort(int arr_count, int *arr)
{
	for (int i = 0; i < arr_count - 1; ++i) {
		int min = arr[i];
		int pos = i;
		for (int j = i + 1; j < arr_count; ++j) {
			if (min > arr[j]) {
				min = arr[j];
				pos = j;
			}
		}
		int temp = arr[i];
		arr[i] = min;
		arr[pos] = temp;
	}
	
	return arr;
}

int main(int argc, char *argv[])
{
	if (argc != 2) { exit(EXIT_FAILURE); }

	srand(time(NULL));

	int arr_count = strtol(argv[1], NULL, 10);
	int *vector = (int *) malloc(arr_count * sizeof(int));

	for (int i = 0; i < arr_count; ++i)
		vector[i] = rand() % arr_count;
	
	printArray(arr_count, vector);
	vector = selectionSort(arr_count, vector);
	printArray(arr_count, vector);
	
	return 0;
}
