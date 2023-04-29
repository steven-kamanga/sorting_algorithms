#include "sort.h"

/**
 *shell_sort - Sorts an array of integers in ascending order
 *using the Shell sort algorithm, using the Knuth sequence
 *@array: The array to be sorted
 *@size: The size of the array
 *Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, inner, outer;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap *3 + 1;

	while (gap > 0)
	{
		for (outer = gap; outer < size; outer++)
		{
			temp = array[outer];
			inner = outer;

			while (inner > gap - 1 && array[inner - gap] >= temp)
			{
				array[inner] = array[inner - gap];
				inner -= gap;
			}

			array[inner] = temp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
