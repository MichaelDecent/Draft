#include "sort.h"
/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 0);
}
/**
 * lomuto_partition - a type of partitioning scheme
 * @array: the array to be sorted
 * @size: size of the array
 * @low: lower bound of the array
 * @high: higher of the array
 *
 * Return: the index_pivot of the array
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int i;
	int pivot = array[high];
	int pivot_idx = low;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (pivot_idx < i)
			{
				swap_ints(&array[pivot_idx], &array[i]);
				print_array(array, size);
			}
			pivot_idx++;
		}
	}
	if (array[pivot_idx] > pivot)
	{
		swap_ints(&array[pivot_idx], &array[high]);
		print_array(array, size);
	}
	return (pivot_idx);
}

/**
 * sort - performs thr actual sorting
 * @array: the array to be sorted
 * @size: size of the array
 * @low: lower bound of the array
 * @high: higher of the array
 */
void sort(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);
		sort(array, size, low, pivot_idx - 1);
		sort(array, size, pivot_idx + 1, high);
	}
}
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
