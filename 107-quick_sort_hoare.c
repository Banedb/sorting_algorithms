#include "sort.h"

/**
 * quick_sort_hoare_recursive - recursive implementation of
 * Hoare's quick sort algorithm. Pivot is the last element.
 * @array: array to be sorted
 * @size: size of the array
 * @low: beginning of array or sub-array to be sorted
 * @high: end of array or sub-array to be sorted
 */
void quick_sort_hoare_recursive(int *array, size_t size, int low, int high)
{
	int pivot, left, right, temp;

	if (low >= high)
		return;

	pivot = array[high];
	for (right = high, left = low; left < right;)
	{
		while (array[left] < pivot)
			left++;
		while (array[right] > pivot)
			right--;
		if (left < right)
		{
			temp = array[left];
			array[left++] = array[right];
			array[right--] = temp;
			print_array(array, size);
		}

	}
	quick_sort_hoare_recursive(array, size, low, left - 1);
	quick_sort_hoare_recursive(array, size, left, high);
}


/**
 * quick_sort_hoare - initiates quick_sort_hoare_recursive
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_hoare_recursive(array, size, 0, size - 1);
}
