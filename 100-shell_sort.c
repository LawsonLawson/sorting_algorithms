#include "sort.h"

/**
 * shell_sort - Implements the shell sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Description: Shell Sort is a variation of insertion sort. It starts by
 * sorting pairs of elements far apart from each other, the progressively
 * reduces the gap between elements to be compared. The gap starts with a
 * large value and is reduced until it becomes 1. After each iteration, the
 * elements with a gap are compared and swapped if necessary, until the entire
 * arry is sorted.
 */
void shell_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, j = 0;
	size_t gap = 0;

	/* Check for NULL array or size less than 2 */
	if (array == NULL || size < 2)
		return;

	/* Initialize the gap using the Knuth's sequence */
	for (gap = 1; gap < (size / 3); gap = gap * 3 + 1)
	;

	/* Continue until gap becomes 0 */
	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp;
					j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3; /* Reduce the gap */
		print_array(array, size);
	}
}
