#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using the section sort
 * algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t current_index, min_index, unsorted_index;

	if (size <= 1) /* No need to sort if the array is of 1 or 0 elements */
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		min_index = current_index;

		/* Find the index of minimum element in the unsorted array */
		for (unsorted_index = current_index + 1; unsorted_index < size;
				unsorted_index++)
		{
			if (array[unsorted_index] < array[min_index])
				min_index = unsorted_index;
		}
		/* Swap minimum element with current element if they differ */
		if (min_index != current_index)
		{
			temp = array[current_index];
			array[current_index] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
