#include "sort.h"

/**
 *merge_sub - Merges the subarrays back together
 *@ar: The array to be sorted
 *@array: The array to be sorted
 *@left: The leftmost index of the subarray
 *@mid: The middle index of the subarray
 *@right: The rightmost index of the subarray
 *Return: Nothing
 */

void merge_sub(int *ar, int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
	{
		if (array[i] < array[j])
		{
			ar[k] = array[i];
			i++;
		}
		else
		{
			ar[k] = array[j];
			j++;
		}
	}

	while (i < mid)
	{
		ar[k] = array[i];
		i++;
		k++;
	}

	while (j < right)
	{
		ar[k] = array[j];
		j++;
		k++;
	}

	for (i = left, k = 0; i < right; i++, k++)
		array[i] = ar[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 *merge_recurr - Recursively splits the array into subarrays
 *and merges them back together
 *@ar: The array to be sorted
 *@array: The array to be sorted
 *@left: The leftmost index of the subarray
 *@right: The rightmost index of the subarray
 *Return: Nothing
 */

void merge_recurr(int *ar, int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = (right - left) / 2 + left;
		merge_recurr(ar, array, left, mid);
		merge_recurr(ar, array, mid, right);
		merge_sub(ar, array, left, mid, right);
	}
}

/**
 *merge_sort - Sorts an array of integers in ascending order
 *using the Merge sort algorithm
 *@array: The array to be sorted
 *@size: The size of the array
 *Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
    int *ar;

    if (array == NULL || size < 2)
        return;

    ar = malloc(sizeof(int) * size);
    if (ar == NULL)
        return;

    merge_recurr(ar, array, 0, size);

    free(ar);
}
