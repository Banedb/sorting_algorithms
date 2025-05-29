#include "sort.h"

/**
 * bitonic_merge - recursively merges a bitonic sequence in a given direction
 * @array: array to be sorted
 * @size: total size of the original array
 * @cut: size of the current sub-array
 * @dir: side being sorted - Up (1) || Down (0)
 */
void bitonic_merge(int *array, size_t size, size_t cut, size_t dir)
{
	size_t i, mid = cut / 2;
	int temp;

	if (!array || cut < 2)
		return;
	for (i = 0; i < mid; i++)
	{
		if ((dir && array[i] > array[i + mid]) ||
		    (!dir && array[i] < array[i + mid]))
		{
			temp = array[i];
			array[i] = array[i + mid];
			array[i + mid] = temp;
		}
	}
	bitonic_merge(array, size, mid, dir);
	bitonic_merge(array + mid, size, cut - mid, dir);
}


/**
 * bitonic_sort_recursive - implements the bitonic sort algorithm
 * @array: array to be sorted
 * @size: total size of the original array
 * @cut: size of the current sub-array
 * @dir: side being sorted - Up (1) || Down (0)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t cut, size_t dir)
{
	size_t mid = cut / 2;

	if (!array || cut < 2)
		return;

	printf("Merging [%ld/%ld] (%s):\n", cut, size, dir ? "UP" : "DOWN");
	print_array(array, cut);
	bitonic_sort_recursive(array, size, mid, 1);
	bitonic_sort_recursive(array + mid, size, cut - mid, 0);

	bitonic_merge(array, size, cut, dir);

	printf("Result [%ld/%ld] (%s):\n", cut, size, dir ? "UP" : "DOWN");
	print_array(array, cut);
}

/**
 * bitonic_sort - initiates the bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, size, size, 1);
}
