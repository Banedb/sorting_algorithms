#include "sort.h"

/**
 * heapify - Transform a binary tree into a max heap.
 *
 * This function rearranges the elements of a binary tree represented as an
 * array into a max heap, starting from a specified node.
 *
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @root: The root node of the binary tree.
 * @current: The current node being considered for heapification.
 */
void heapify(int *array, size_t size, size_t root, size_t current)
{
	size_t left, right, large;
	int temp;

	left = 2 * current + 1;
	right = 2 * current + 2;
	large = current;

	if (left < root && array[left] > array[large])
		large = left;
	if (right < root && array[right] > array[large])
		large = right;

	if (large != current)
	{
		temp = array[current];
		array[current] = array[large];
		array[large] = temp;
		print_array(array, size);
		heapify(array, size, root, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = *array;
		*array = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
