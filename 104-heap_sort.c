#include "sort.h"

/**
 *heap_sort - Sorts an array of integers in ascending order
 *using the Heap sort algorithm
 *@array: The array to be sorted
 *@size: The size of the array
 *Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (size < 2)
		return;

	for (i = size / 2 - 1;
		(int) i >= 0; i--)
		heaps(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heaps(array, i, 0, size);
	}
}

/**
 *heaps - Sorts an array of integers in ascending order
 *using the Heap sort algorithm
 *@array: The array to be sorted
 *@size: The size of the array
 *@i: The index of the root
 *@size2: The size of the array
 *Return: Nothing
 */

void heaps(int *array, size_t size, size_t i, size_t size2)
{
	size_t max = i;
	size_t left = 2 *i + 1;
	size_t right = 2 *i + 2;
	int temp;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		print_array(array, size2);
		heaps(array, size, max, size2);
	}
}