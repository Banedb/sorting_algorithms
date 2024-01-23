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

	/* Print the sorted array */
	print_array(array, size);
}

/**
 * quicksort - Recursive function for Quick sort with Lomuto partition scheme
 *
 * @array: Array to be sorted
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 *
 * Description: This function performs the recursive Quick sort using Lomuto
 *              partition scheme on a specific partition of the array
 *
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pidx;

	if (low < high)
	{
		/* Get the partition index */
		pidx = lomuto_partition(array, low, high, size);

		/* Recursively sort the subarrays */
		quicksort(array, low, pidx - 1, size);
		quicksort(array, pidx + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: Array to be partitioned
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 *
 * Description: This function chooses the last element as the pivot,
 *              partitions the array, and returns the partition index.
 *
 * Return: Partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/* Swap array[i] and array[j] */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			/* Print the array after each swap */
			print_array(array, size);
		}
	}

	/* Swap array[i + 1] and array[high] to place pivot in correct pos */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	/* Print the array after each swap */
	print_array(array, size);

	return (i + 1);
}
