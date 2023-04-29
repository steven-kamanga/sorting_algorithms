#include "sort.h"

/**
 *selection_sort - Sorts an array of integers in ascending order
 *using the Selection sort algorithm
 *@array: The array to be sorted
 *@size: The size of the array
 *Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t inner, outer, minimum;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (inner = 0; inner < size - 1; inner++)
	{
		minimum = inner;

		for (outer = inner + 1; outer < size; outer++)
		{
			if (array[outer] < array[minimum])
				minimum = outer;
		}

		if (minimum != inner)
		{
			temp = array[inner];
			array[inner] = array[minimum];
			array[minimum] = temp;

			print_array(array, size);
		}
	}
}
