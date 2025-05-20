#include "sort.h"
/**
 * recursive_merge_sort - helper function to recursively sort and merge
 * @array: array to be sorted
 * @size: size of the array
 * @buffer: temporary buffer to store sorted array
 */
void recursive_merge_sort(int *array, size_t size, int *buffer)
{
	size_t i, left, right, mid;

	if (!array || size < 2)
		return;

	mid = size / 2;
	recursive_merge_sort(array, mid, buffer);
	recursive_merge_sort(array + mid, size - mid, buffer);
	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	for (i = 0, left = 0, right = mid; i < size; i++)
	{
		if (left < mid && right < size)
		{
			if (array[left] < array[right])
				buffer[i] = array[left++];
			else
				buffer[i] = array[right++];
		}
		else if (left < mid)
			buffer[i] = array[left++];
		else if (right < size)
			buffer[i] = array[right++];
	}
	for (i = 0; i < size; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array, size);
}


/**
 * merge_sort - implements the top down merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(array[0]) * size);
	if (!buffer)
		return;

	recursive_merge_sort(array, size, buffer);

	free(buffer);
}
