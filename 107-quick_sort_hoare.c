#include "sort.h"

void quick_recurr(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_recurr(array, 0, size - 1, size);
}

/**
 * quick_recurr - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * @low: lowest index of the partition to be sorted
 * @high: highest index of the partition to be sorted
 * Return: void
 */

void quick_recurr(int *array, int low, int high, size_t size)
{
    int p;

    if (low < high)
    {
        p = partition(array, low, high, size);
        quick_recurr(array, low, p, size);
        quick_recurr(array, p + 1, high, size);
    }
}

/**
 * partition - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * @low: lowest index of the partition to be sorted
 * @high: highest index of the partition to be sorted
 * Return: void
 */

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;
    int temp;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
    }
}
