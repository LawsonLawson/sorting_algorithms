#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm.
 *
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = NULL, *sorted_end = NULL;
	listint_t *prev_node = NULL, *next_node = NULL;
	listint_t *unsorted_node = NULL;

	if (!list || ((*list == NULL) || ((*list)->next == NULL)))
		return;
	current_node = (*list)->next;
	sorted_end = *list;
	while (current_node) /* Iterate through list */
	{
		if (current_node->n >= sorted_end->n)
		{
			sorted_end = current_node;
			current_node = sorted_end->next;
		}
		if (current_node && (current_node->n < sorted_end->n))
		{
			unsorted_node = current_node->prev;
			while (unsorted_node &&
				(unsorted_node->n > current_node->n))
			{/* Iterate backwards until current position found */
				prev_node = unsorted_node->prev;
				next_node = current_node->next;
				/* Perfom the swap */
				unsorted_node->next = current_node->next;
				current_node->next = unsorted_node;
				current_node->prev = prev_node;
				if (next_node)
					next_node->prev = unsorted_node;
				if (prev_node)
					prev_node->next = current_node;
				unsorted_node->prev = current_node;
				unsorted_node = current_node->prev;
				if (unsorted_node == NULL)
					*list = current_node;
				print_list(*list); /* Print the current list */
			}
			current_node = sorted_end->next;
		}
	}
}
