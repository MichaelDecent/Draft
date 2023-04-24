#include "sort.h"
/**
 * selection_sort - a function that sorts an array of
 * integers in ascending order using the Selection sort algorithm
 * @array: array of element to be sorted
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t j, i;
	size_t min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap_ints(&array[i], &array[min_idx]);
			print_array(array, size);
		}

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
