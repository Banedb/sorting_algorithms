#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void recursive_quick_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *current, listint_t *temp);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void recursive_merge_sort(int *array, size_t size, int *buffer);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t cut, size_t dir);
void bitonic_sort_recursive(int *array, size_t size, size_t cut, size_t dir);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare_recursive(int *array, size_t size, int low, int high);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
