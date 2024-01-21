#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *array, size_t size) {
	size_t i, k, j;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				for (k = 0; k < size; k++) {
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}
	}
}
