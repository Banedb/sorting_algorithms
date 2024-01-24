#include "sort.h"

/**
 * bitonic_merge - Merges two halves of an array in a Bitonic manner
 * @array: The array to be merged
 * @left: left side
 * @right: right side
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int left, int right, int dir)
{
	int i, temp, step = (left + right) / 2, half = (right - left + 1) / 2;

	if (right - left >= 1)
	{
		for (i = left; i < left + half; i++)
		{
			if (dir == (array[i] > array[i + half]))
			{
				temp = array[i + half];
				array[i + half] = array[i];
				array[i] = temp;
			}
		}
		bitonic_merge(array, left, step, dir);
		bitonic_merge(array, step + 1, right, dir);
	}
}


/**
 * bitonic_recursive - Recursively performs Bitonic sort on an array
 * @array: The array to be sorted
 * @left: left side
 * @right: right side
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 * @size: The size of the chunk being sorted
 */
void bitonic_recursive(int *array, int left, int right, int dir, size_t size)
{
	int step;

	if (right - left >= 1)
	{
		step = (right + left) / 2;
		printf("Merging [%d/%lu] ", right - left + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
		bitonic_recursive(array, left, step, 1, size);
		bitonic_recursive(array, step + 1, right, 0, size);
		bitonic_merge(array, left, right, dir);
		printf("Result [%d/%lu] ", right - left + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + left, right - left + 1);
	}
}

/**
 * bitonic_sort - Sorts an array of ints in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_recursive(array, 0, size - 1, 1, size);
}
