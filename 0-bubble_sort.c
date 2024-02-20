#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The length of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t outer_index, inner_index;
	int temp, swap_flag;

	if (size < 2)
		return; /* No need to sort */

	for (outer_index = 0; outer_index < size; outer_index++)
	{
		swap_flag = 0;

		for (inner_index = 0; inner_index < size - 1; inner_index++)
		{
			if (array[inner_index] > array[inner_index + 1])
			{
				/* Swap elements */
				temp = array[inner_index];
				array[inner_index] = array[inner_index + 1];
				array[inner_index + 1] = temp;

				print_array(array, size);
				swap_flag = 1;
			}
		}
		if (swap_flag == 0)
			return; /* If swap was not made, array is already sorted */
	}
}
