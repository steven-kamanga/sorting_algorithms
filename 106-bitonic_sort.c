#include "sort.h"

/**
 * bitonic_sort - Sort an array of integers in ascending order using the
 * Bitonic sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 */

void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    bitonic_recurr(array, 0, size, size, 1);
}

/**
 * bitonic_recurr - Sort an array of integers in ascending order using the
 * Bitonic sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @size2: Number of elements in @array
 * @dir: direction of the sort
 *
 */

void bitonic_recurr(int *array, int low, int high, size_t size, int dir)
{
    int mid;

    if (high - low > 1)
    {
        mid = (high + low) / 2;
        printf("Merging [%d/%d]", high - low, (int)size);
        if(dir)
            printf("(UP):\n");
        else
            printf("(DOWN):\n");
        print_array(array + low, high - low);
        bitonic_recurr(array, low, mid, size, 1);
        bitonic_recurr(array, mid, high, size, 0);
        bitonic_merge(array, low, high, size, dir);
        printf("Result [%d/%lu] ", high - low + 1, size);
        if(dir)
            printf("(UP):\n");
        else
            printf("(DOWN):\n");
        print_array(array + low, high - low);
    }
}

/**
 * bitonic_merge - Sort an array of integers in ascending order using the
 * Bitonic sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @size2: Number of elements in @array
 * @dir: direction of the sort
 *
 */

void bitonic_merge(int *array, int low, int high, size_t size, int dir)
{
    int i, temp;

    if (high - low > 1)
    {
        for (i = low; i < (high + low) / 2; i++)
        {
            if (dir == (array[i] > array[i + (high - low) / 2]))
            {
                temp = array[i];
                array[i] = array[i + (high - low) / 2];
                array[i + (high - low) / 2] = temp;
            }
        }
        bitonic_merge(array, low, (high + low) / 2, size, dir);
        bitonic_merge(array, (high + low) / 2, high, size, dir);
    }
}