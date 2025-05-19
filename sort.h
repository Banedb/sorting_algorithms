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
void quick_sort(int *array, size_t size);
void quicksort(int *array, int left, int right, size_t size);
int lomuto_partition(int *array, int left, int right, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *current, listint_t *temp);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge(int *temp_array, int *array, size_t left, size_t mid, size_t right);
void merge_recursive(int *temp_array, int *array, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_merge(int *array, int left, int right, int dir);
void bitonic_recursive(int *array, int left, int right, int dir, size_t size);
void bitonic_sort(int *array, size_t size);
int hoare_partition(int *array, size_t size, int left, int right);
void quicksort_hoare(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
