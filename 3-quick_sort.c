#include "sort.h"

/**
 *quick_sort - Sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: The array to be sorted
 *@size: The size of the array
 *Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 *quicksort - Sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: The array to be sorted
 *@lo: The lower bound of the array
 *@hi: The upper bound of the array
 *@size: The size of the array
 *Return: Nothing
 */

void quicksort(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 *partition - Partitions an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: The array to be sorted
 *@lo: The lower bound of the array
 *@hi: The upper bound of the array
 *@size: The size of the array
 *Return: The index of the pivot
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1, j, temp;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = temp;
	if (i + 1 != hi)
		print_array(array, size);
	return (i + 1);
}
