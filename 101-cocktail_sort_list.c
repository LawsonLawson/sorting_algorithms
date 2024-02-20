#include "sort.h"

/**
 * forward_bubble_sort - Performs bubble sort from left to right.
 *
 * Description: This function implements the bubble sort algorithm to sort a
 * doubly linked list of integers from left to right.
 *
 * @list: Pointer to a doubly linked list of integers.
 * @current_node: Pointer to the current position in the linked list
 * (start of the linked list).
 *
 * Return: 1 when a swap occurs, 0 otherwise.
 */
int forward_bubble_sort(listint_t **list, listint_t **current_node);

/**
 * backward_bubble_sort - Performs bubble sort from right to left.
 *
 * Description: This function implements the bubble sort algorithm to sort a
 * doubly linked list of integers from right to left.
 *
 * @list: Pointer to a doubly linked list of integers.
 * @current_node: Pointer to the current position in the linked list
 * (end of the linked list).
 *
 * Return: 1 when a swap occurs, 0 otherwise.
 */
int backward_bubble_sort(listint_t **list, listint_t **current_node);

/**
 * cocktail_sort_list - Sorts a list of integers using the Cocktail Sort
 * Algorithm.
 *
 * Description: This function sorts a doubly linked list of integers using the
 * Cocktail Sort Algorithm, which iteratively performs forward and backward
 * passes through the list until the list is sorted.
 *
 * @list: Pointer to a doubly linked list of integers.
 */
void cocktail_sort_list(listint_t **list);

/**
 * forward_bubble_sort - Performs bubble sort from left to right.
 *
 * Description: This function implements the bubble sort algorithm to sort a
 * doubly linked list of integers from left to right.
 *
 * @list: Pointer to a doubly linked list of integers.
 * @current_node: Pointer to the current position in the linked list
 * (start of the linked list).
 *
 * Return: 1 when a swap occurs, 0 otherwise.
 */
int forward_bubble_sort(listint_t **list, listint_t **current_node)
{
	listint_t *next_node;
	int is_swapped = 0;

	while ((*current_node)->next != NULL)
	{
		next_node = (*current_node)->next;
		if ((*current_node)->n > next_node->n)
		{
			if ((*current_node)->prev != NULL)
				(*current_node)->prev->next = next_node;
			else
				*list = next_node;

			if (next_node->next != NULL)
				next_node->next->prev = *current_node;

			(*current_node)->next = next_node->next;
			next_node->prev = (*current_node)->prev;
			(*current_node)->prev = next_node;
			next_node->next = (*current_node);

			is_swapped = 1;
			print_list((const listint_t *)*list);
		}
		else
			*current_node = (*current_node)->next;
	}

	return (is_swapped);
}

/**
 * backward_bubble_sort - Performs bubble sort from right to left.
 *
 * Description: This function implements the bubble sort algorithm to sort a
 * doubly linked list of integers from right to left.
 *
 * @list: Pointer to a doubly linked list of integers.
 * @current_node: Pointer to the current position in the linked list
 * (end of the linked list).
 *
 * Return: 1 when a swap occurs, 0 otherwise.
 */
int backward_bubble_sort(listint_t **list, listint_t **current_node)
{
	listint_t *previous_node;
	int is_swapped = 0;

	while ((*current_node)->prev != NULL)
	{
		previous_node = (*current_node)->prev;
		if ((*current_node)->n < previous_node->n)
		{
			if (previous_node->prev != NULL)
				previous_node->prev->next = *current_node;
			else
				*list = *current_node;
			if ((*current_node)->next != NULL)
				(*current_node)->next->prev = previous_node;

			previous_node->next = (*current_node)->next;
			(*current_node)->prev = previous_node->prev;
			previous_node->prev = *current_node;
			(*current_node)->next = previous_node;

			is_swapped = 1;
			print_list((const listint_t *)*list);
		}
		else
			*current_node = (*current_node)->prev;
	}

	return (is_swapped);
}

/**
 * cocktail_sort_list - Sorts a list of integers using the Cocktail Sort
 * Algorithm.
 *
 * Description: This function sorts a doubly linked list of integers using the
 * Cocktail Sort Algorithm, which iteratively performs forward and backward
 * passes through the list until the list is sorted.
 *
 * @list: Pointer to a doubly linked list of integers.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node;
	int is_swapped;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	do {
		current_node = *list;

		/* Forward sort */
		is_swapped = forward_bubble_sort(list, &current_node);
		if (!is_swapped)
			break;

		/* Backward sort */
		is_swapped = backward_bubble_sort(list, &current_node);
		if (!is_swapped)
			break;
	} while (is_swapped);
}
