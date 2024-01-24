#include "sort.h"

/**
 * merge - Merges two sub-arrays into a single sorted array.
 * @temp_array: Temporary array for merging sub-arrays
 * @array: Pointer to the original array.
 * @left: Pointer to the left sub-array.
 * @mid: middle.
 * @right: Pointer to the right sub-array.
 */
void merge(int *temp_array, int *array, size_t left,
		    size_t mid, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid  - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
	{
		if (array[i] < array[j])
			temp_array[k] = array[i++];
		else
			temp_array[k] = array[j++];
	}

	while (i < mid)
		temp_array[k++] = array[i++];
	while (j < right)
		temp_array[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = temp_array[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_recursive - Recursively divides and sorts the array using merge sort.
 * @temp_array: Temporary array for merging sub-arrays
 * @array: Pointer to the array to be sorted.
 * @left: left index of the sub-array.
 * @right: right index of the sub-array.
 */
void merge_recursive(int *temp_array, int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = (right - left) / 2 + left;
		merge_recursive(temp_array, array, left, mid);
		merge_recursive(temp_array, array, mid, right);
		merge(temp_array, array, left, mid, right);
	}
}


/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              top-down merge sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (!array || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);

	merge_recursive(temp_array, array, 0, size);
	free(temp_array);
}
