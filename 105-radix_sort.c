#include "sort.h"

/**
 * radix_counting_sort - counting sort implementation for radix sort
 * @array: array to be sorted
 * @size: size of the array
 * @exp: digit position tracker
 */
void radix_counting_sort(int *array, size_t size, int exp)
{
	int num, j, count[10] = {0};
	int *output = malloc(sizeof(array[0]) * size);
	size_t i;

	/* count occurences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* adjust count array to reflect positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* build output array from back to preserve stability */
	for (j = size - 1; j >= 0; j--)
	{
		num = (array[j] / exp) % 10;
		output[--count[num]] = array[j];
	}
	/* copy to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}


/**
 * radix_sort - implements the LSD radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;
	size_t i;

	if (!array || size < 2)
		return;

	/* Get max value */
	for (i = 1, max = array[0]; i < size; i++)
		if (max < array[i])
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_counting_sort(array, size, exp);
		print_array(array, size);
	}
}
