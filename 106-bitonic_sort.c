#include <stdio.h>

/**
 * bitonic_merge - Merges two halves of an array in a Bitonic manner
 * @array: The array to be merged
 * @size: The size of the array
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 * @chunk_size: The size of the chunk being merged
 */
void bitonic_merge(int *array, size_t size, int dir, size_t chunk_size)
{
	size_t i, half;

	if (chunk_size > 1)
	{
		half = chunk_size / 2;
		for (i = 0; i < size; i++)
		{
			if ((i < half && array[i] > array[i + half]) ||
			    (i >= half && array[i] < array[i - half]))
			{
				temp = array[i];
				array[i] = array[i + half];
				array[i + half] = temp;
				printf("Result [%lu/%lu] (%s):\n", half, size, dir ? "UP" : "DOWN");
				print_array(array, size);
			}
		}

		bitonic_merge(array, half, dir, half);
		bitonic_merge(array + half, half, dir, half);
	}
}


/**
 * bitonic_recursive - Recursively performs Bitonic sort on an array
 * @array: The array to be sorted
 * @size: The size of the array
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 * @chunk_size: The size of the chunk being sorted
 */
void bitonic_recursive(int *array, size_t size, int dir, size_t chunk_size)
{
	size_t half;
	if (chunk_size > 1)
	{
		half = chunk_size / 2;

		printf("Merging [%lu/%lu] (%s):\n", half, size, dir ? "UP" : "DOWN");
		print_array(array, size);

		bitonic_recursive(array, half, 1, half);
		bitonic_recursive(array + half, half, 0, half);

		bitonic_merge(array, size, dir, chunk_size);
	}
}

/**
 * bitonic_sort - Sorts an array of ints in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_recursive(array, size, 1, size);
}
