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

/* Printing Function */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting Algorithms Functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


/* Helping Function */
int lomuto_partition(int *array, size_t size, int low, int high);
void sort(int *array, size_t size, int low, int high);
void swap_ints(int *a, int *b);
void swapNodes(listint_t **list, listint_t *node1, listint_t *node2);
void split_merge_TopDown(int *sub_array, int *buffer, int low, int high);
void merge_SubArray(int *sub_array, int *buffer, int low, int mid, int high);
void radixCounting_sort(int *array, size_t size, int pos);
int hoare_partition(int *array, size_t size, int low, int high);

#endif
