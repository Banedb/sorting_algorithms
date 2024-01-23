#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Description: Function uses the Quick sort algorithm with Lomuto partition
 *              scheme to sort the given array of ints in ascending order
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Call the recursive quicksort function */
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Recursive function for Quick sort with Lomuto partition scheme
 *
 * @array: Array to be sorted
 * @left: left index of the partition
 * @right: Right index of the partition
 * @size: Size of the array
 *
 * Description: This function performs the recursive Quick sort using Lomuto
 *              partition scheme on a specific partition of the array
 *
 * Return: void
 */
void quicksort(int *array, int left, int right, size_t size)
{
	int pidx;

	if (left < right)
	{
		/* Get the partition index */
		pidx = lomuto_partition(array, left, right, size);

		/* Recursively sort the subarrays */
		quicksort(array, left, pidx - 1, size);
		quicksort(array, pidx + 1, right, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: Array to be partitioned
 * @left: Left(low) index of the partition
 * @right: Right(unsorted) index of the partition
 * @size: Size of the array
 *
 * Description: This function chooses the last element as the pivot,
 *              partitions the array, and returns the partition index.
 *
 * Return: Partition index
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right], i = left, j, temp;

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (right != i)
	{
		array[right] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}
	return (i);
}
