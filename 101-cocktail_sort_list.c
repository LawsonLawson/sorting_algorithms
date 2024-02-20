#include "sort.h"


/**
 * swap_nodes - Swaps the position of two nodes in a linked list.
 *
 * @left_node: Pointer to the left node to swap.
 * @right_node: Pointer to the right node to swap.
 */
void swap_nodes(listint_t *left_node, listint_t *right_node);

/**
 * get_pointer - Retrieves the pointer at a specified position in the list.
 *
 * @pointer_type: Whether to retrieve the front or end pointer.
 * @position: The position in the list to retrieve the pointer.
 * @list: The list.
 *
 * Return: Pointer at the specified position, or NULL if not found.
 */
listint_t *get_pointer(size_t pointer_type, size_t position, listint_t **list);

/**
 * get_list_length - Calculates the length of a linked list.
 *
 * @list: Pointer to the head of the list.
 *
 * Return: Length of the linked list.
 */
int get_list_length(listint_t **list);

/**
 * cocktail_sort_list - Sorts a linked list in ascending order using the
 * cocktail shaker sort algorithm.
 *
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - Sorts a linked list in ascending order using the
 * cocktail shaker sort algorithm.
 *
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *list_start = NULL, *list_end = NULL;
	listint_t *move_node = NULL, *current_node = NULL;
	size_t pass_count = 0;
	int swap_flag = 0; /* To track wether any swaps occured in a pass */

	/* Check if the list is NULL or has 1 or 0 elements */
	if (!(*list) || !list || !((*list)->next))
		return;

	/* Set list_start, list_end, and current_node pointers */
	list_start = *list;
	list_end = list_start;
	current_node = list_start;

	/* Find the last node in the list */
	while (list_end->next)
		list_end = list_end->next;

	/* Iterate until list_start and list_end converge */
	while (list_start != list_end)
	{
		swap_flag = 0; /* Reset the swap flag for each pass */

		/* Forward pass: bubble large element to end */
		while (current_node != list_end)
		{
			move_node = current_node->next;
			if (current_node->n > move_node->n)
			{
				swap_nodes(current_node, move_node);

				if (move_node->prev == NULL)
					*list = move_node;
				print_list(*list);
				swap_flag = 1; /* Swap occured */
			}
			current_node = move_node;
		}
		list_end = get_pointer(1, pass_count, list);
		current_node = list_end;

		/* Backward pass: bubble smallest element to start */
		while (current_node != list_start)
		{
			move_node = current_node->prev;
			if (current_node->n < move_node->n)
			{
				swap_nodes(move_node, current_node);
				if (current_node->prev == NULL)
					*list = current_node;
				print_list(*list);
				swap_flag = 1; /* Swap occured */
			}
			current_node = move_node;
		}
		list_start = get_pointer(0, pass_count, list);
		pass_count++;

		if (!swap_flag) /* If there was no swap, list is sorted */
			return;
	}
}

/**
 * swap_nodes - Swaps the position of two nodes in a linked list.
 *
 * @left_node: Pointer to the left node to swap.
 * @right_node: Pointer to the right node to swap.
 */
void swap_nodes(listint_t *left_node, listint_t *right_node)
{
	/* Store the previous and next nodes of the nodes to be swapped */
	listint_t *left_prev = left_node->prev;
	listint_t *right_next = right_node->next;

	/* Adjust pointers to swap the nodes */
	left_node->next = right_node->next;
	right_node->next = left_node;
	right_node->prev = left_prev;

	/* Update pointers of adjacent nodes */
	if (right_next)
	{
		right_next->prev = left_node;
	}
	if (left_prev)
	{
		left_prev->next = right_node;
	}
	left_node->prev = right_node;
}

/**
 * get_pointer - Retrieves the pointer at a specified position in the list.
 *
 * @pointer_type: Whether to retrieve the front or end pointer.
 * @position: The position in the list to retrieve the pointer.
 * @list: The list.
 *
 * Return: Pointer at the specified position, or NULL if not found.
 */
listint_t *get_pointer(size_t pointer_type, size_t position, listint_t **list)
{
	listint_t *pointer = *list; /* Initialize pointer to the head */
	size_t count = 0;

	/* Traverse the list to find the desired position */
	if (pointer_type == 1) /* Retrieve pointer from the end */
	{
		count = get_list_length(list) - position;
		while (count != position + 1)
		{
			pointer = pointer->next;
			count--;
		}
	}
	else /* Else we retrieve pointer from the front */
	{
		count = 0;
		while (count != position + 1)
		{
			pointer = pointer->next;
			count++;
		}
	}

	return (pointer);
}

/**
 * get_list_length - Calculates the length of a linked list.
 *
 * @list: Pointer to the head of the list.
 *
 * Description: This function calculates the lenght of the linked list by
 * traversing the list from the head to the end and counting the nodes.
 *
 * Return: Length of the linked list.
 */
int get_list_length(listint_t **list)
{
	listint_t *current = *list; /* Current pointer to the head of list */
	int count = 0;

	/* Traverse the list and count the nodes */
	while (current)
	{
		current = current->next;
		count++;
	}

	return (count); /* Return the count */
}
