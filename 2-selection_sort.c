#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Description: This function uses the Selection sort algorithm to
 *              sort the given array of integers in ascending order.
 *              It prints the array after each time two elements are swapped.
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
