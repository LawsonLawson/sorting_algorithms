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

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* Auxilliary(helper) function prototypes */
void swap(int *x, int *y);
void sift_down(int *array, size_t root, size_t size, size_t base);
void bitonic_merge(int *array, size_t size, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t seq, char flow);
void _quicksort(int *array, int size, int left, int right, int part_idx);
int partition(int *array, int size, int left, int right);


#endif /* SORT_H */
