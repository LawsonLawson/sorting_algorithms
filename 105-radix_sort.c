#include "sort.h"

/**
 * new_digit_node - Creates a new digit node with a given value.
 *
 * @value: The value to be stored in the new digit node.
 *
 * Return: A pointer to the newly created digit node.
 */
digit_node *new_digit_node(int value)
{
	digit_node *node = malloc(sizeof(digit_node));

	if (node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	node->value = value;
	node->next = NULL;

	return (node);
}

/**
 * radix_sort - Sorts an array of integers an ascending order using the Radix
 * sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, place, digit;
	size_t i, j, index;
	digit_node *queues[10] = {NULL};
	digit_node *node;

	if (array == NULL || size < 2)
		return; /* Nothing to sort */

	max_value = array[0];
	for (i = 1; i < size; i++) /* Find max value in array */
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	for (place = 1; max_value / place > 0; place *= 10) /* Counting ... */
	{
		for (i = 0; i < size; i++)
		{/* Distribute elements into queues based on the current */
			digit = (array[i] / place) % 10;
			node = new_digit_node(array[i]);

			node->next = queues[digit];
			queues[digit] = node;
		}
		index = 0;
		for (j = 0; j < 10; j++)
		{/* Collect elements from queues back into the array */
			while (queues[j] != NULL)
			{
				digit_node *temp = queues[j];

				array[index++] = temp->value;
				queues[j] = queues[j]->next;
				free(temp);
			}
		}
		print_array(array, size); /* Print array after each pass */
	}
}
