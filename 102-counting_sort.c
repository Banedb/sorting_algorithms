#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, *count_array, *s_array, max, num;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = malloc(sizeof(size_t) * (max + 1));
	s_array = malloc(sizeof(int) * size);

	for (j = 0; j <= max; j++)
		count_array[j] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		count_array[num] += 1;
	}
	for (j = 1; j <= max; j++)
		count_array[j] += count_array[j - 1];
	print_array(count_array, max + 1);
	for (i = 0; i < size; i++)
	{
		s_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = s_array[i];

	free(count_array);
	free(s_array);
}
