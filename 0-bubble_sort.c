#include "sort.h"

/**
 * bubble_sort - Sort array of integers in ascending order using basic for loops
 * @array: the array
 * @size: The size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
    size_t inner_loop, outer_loop;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (inner_loop = 0; inner_loop < size - 1; inner_loop++)
    {
        for (outer_loop = 1; outer_loop < size - inner_loop; outer_loop++)
        {
            if (array[outer_loop - 1] > array[outer_loop])
            {
                temp = array[outer_loop - 1];
                array[outer_loop - 1] = array[outer_loop];
                array[outer_loop] = temp;

                print_array(array, size);
            }
        }
    }
}