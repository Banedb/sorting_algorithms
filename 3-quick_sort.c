#include "sort.h"
/**
 * recursive_quick_sort - recursive implementation of
 * Lomuto's quick sort algorithm. Pivot is the last element.
 * @array: the array to be sorted
 * @size: size of the array
 * @low: beginning of array or sub-array to be sorted
 * @high: end of array or sub-array to be sorted
 */
void recursive_quick_sort(int *array, size_t size, int low, int high)
{
	int i, min_index, temp;

	if (low >= high)
		return;

	for (i = low, min_index = low; i < high; i++)
	{
		if (array[i] <= array[high])
		{
			if (i != min_index)
			{
				temp = array[min_index];
				array[min_index] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			min_index++;
		}
	}
	if (min_index != high)
	{
		temp = array[min_index];
		array[min_index] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	/* sort left side */
	recursive_quick_sort(array, size, low, min_index - 1);
	/* sort right side */
	recursive_quick_sort(array, size, min_index + 1, high);
}

/**
 * quick_sort - recursive implementation of the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_quick_sort(array, size, 0, size - 1);
}
