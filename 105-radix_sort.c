#include "sort.h"

/**
 * radix_sort - Sorts an array of integers using LSD Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_num, exp;
	size_t i;

	if (size < 2)
		return;

	/* Find the maximum number to know the number of digits */
	max_num = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}

	/* Perform counting sort for every digit */
	for (exp = 1; max_num / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * count_sort - Perform counting sort on LSD for Radix sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current digit place value (1, 10, 100, ...).
 */
void count_sort(int *array, size_t size, int exp)
{
	const int base = 10;
	int i, *output = malloc(sizeof(int) * size), *count;
	size_t j;

	count = malloc(sizeof(int) * base);
	if (output == NULL || count == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < base; i++)
		count[i] = 0;

	/* Count occurrences of each digit in the current place value */
	for (j = 0; j < size; j++)
		count[(array[j] / exp) % base]++;

	/* Adjust count array to store actual position of digits */
	for (i = 1; i < base; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}

	/* Copy the output array back to the original array */
	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(output);
	free(count);
}
