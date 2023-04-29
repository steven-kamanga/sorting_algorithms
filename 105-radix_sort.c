#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * 
 * @array: The array to be sorted
 * Return: Nothing
 */

void radix_sort(int *array, size_t size)
{
    int maximum;
    size_t i, xxl;

    if (!array || size < 2)
        return;
    
    maximum = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }

    for (xxl = 1; maximum / xxl > 0; xxl *= 10)
    {
        countsort(array, size, xxl);
        print_array(array, size);
    }
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * 
 * @array: The array to be sorted
 * @size: The size of the array
 * @xxl: The size of the array
 * Return: Nothing
 */

void countsort(int *array, size_t size, size_t xxl)
{
    int count_array[10] = {0}, *bound_arr, x, z;
    size_t i, j;

    bound_arr = malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
    {
        x = (array[i] / xxl) % 10;
        count_array[x] += 1;
    }

    for (j = 1; j < 10; j++)
        count_array[j] += count_array[j - 1];
    
    for (z = size - 1; z >= 0; z--)
    {
        x = (array[z] / xxl) % 10;
        bound_arr[count_array[x] - 1] = array[z];
        count_array[x]--;
    }

    for (i = 0; i < size; i++)
        array[i] = bound_arr[i];

    free(bound_arr);
}