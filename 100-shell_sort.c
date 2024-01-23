#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, temp, interval = 1;

	if (array == NULL || size < 2)
		return;
	while (interval <= (int)(size / 3))
		interval = interval * 3 + 1;

	/* Start with the largest interval and reduce it */
	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			/* Shift elements to the right within the interval */
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		/* Print the array after each interval decrease */
		print_array(array, size);

		/* Calculate the next interval using Knuth sequence */
		interval = (interval - 1) / 3;
	}
}
