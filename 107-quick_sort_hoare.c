#include "sort.h"

/**
 * hoare_partition - Performs partition using the Hoare scheme
 * @array: The array to be partitioned
 * @size: The size of the array
 * @left: left side of the partition
 * @right: right side of the partition
 * Return: The final position of the pivot
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, high, low, temp;

	pivot = array[right];
	for (high = left - 1, low = right + 1; high < low;)
	{
		do {
			high++;
		} while (array[high] < pivot);
		do {
			low--;
		} while (array[low] > pivot);

		if (high < low)
		{
			temp = array[high];
			array[high] = array[low];
			array[low] = temp;
			print_array(array, size);
		}
	}

	return (high);
}

/**
 * quicksort_hoare - Perform Quick sort using Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 * @left: The left/lower index of the partition
 * @right: The right /higher index of the partition
 */
void quicksort_hoare(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		quicksort_hoare(array, size, left, part - 1);
		quicksort_hoare(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *         using Quick sort (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, size, 0, size - 1);
}
