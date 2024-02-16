#include "sort.h"


/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function implements the Counting sort algorithm to sort
 * a given array of integers in ascending order. It operates by counting the
 * number of occurences of each unique element in the array and then
 * reconstructing the sorted array based on these counts.
 */
void counting_sort(int *array, size_t size)
{
	size_t array_index;
	int count_index, max_value = 0;
	int *count_array, *sorted_array, position;

	if (size < 2 || array == NULL)
		return;
	for (array_index = 0; array_index < size; array_index++) /* Find max */
	{
		if (array[array_index] > max_value)
			max_value = array[array_index];
	}
	count_array = calloc(max_value + 1, sizeof(int));
	if (!count_array)
		return;
	for (array_index = 0; array_index < size; array_index++)
		count_array[array[array_index]] += 1;
	/* Calculate cumulative counts to determine positions in the array */
	for (count_index = 1; count_index < max_value + 1; count_index++)
		count_array[count_index] += count_array[count_index - 1];
	print_array(count_array, max_value + 1);

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array); /* In case of failure, free allocated mem */
		return;
	}
	/* Reconstruct the sorted array */
	for (array_index = size - 1; (int)array_index >= 0; array_index--)
	{
		position = count_array[array[array_index]];
		sorted_array[position - 1] = array[array_index];
		count_array[array[array_index]] -= 1;
	}
	/* Copy the sorted array back to the original array */
	for (array_index = 0; array_index < size; array_index++)
		array[array_index] = sorted_array[array_index];

	free(count_array); /* Free up */
	free(sorted_array);
}
