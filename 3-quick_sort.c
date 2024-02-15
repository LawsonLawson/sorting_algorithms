#include "sort.h"


/**
 * partition - Partitions the array around a pivot.
 *
 * @array: The array to partition.
 * @low: The lower index of the array segment.
 * @high: The higher index of the array segment.
 * @size: The size of the array.
 *
 * Return: Index of the pivot after partitioning.
 */
int partition(int *array, int low, int high, int size);

/**
 * quick_sort_recursive - Recursive function to implement quick sort.
 *
 * @array: The array to sort.
 * @low: The lower index of the array segment.
 * @high: The higher index of the array segment.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, int size);

/**
 * quick_sort - Sorts an array using quick sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	/* Check for NULL array or size less than 2 */
	if (array == NULL || size < 2)
		return;

	/* Call the recursive function to perform quick sort */
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * partition - Partitions the array around a pivot.
 *
 * @array: The array to partition.
 * @low: The lower index of the array segment.
 * @high: The higher index of the array segment.
 * @size: The size of the array.
 *
 * Return: Index of the pivot after partitioning.
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int smaller_index = low - 1;
	int current_index, temp;

	/* Iterate through the array */
	for (current_index = low; current_index <= high - 1; current_index++)
	{
		if (array[current_index] <= pivot)
		{
			smaller_index++;

			/* If elements differ, swap them */
			if (smaller_index != current_index)
			{
				temp = array[smaller_index];
				array[smaller_index] = array[current_index];
				array[current_index] = temp;

				print_array(array, size);
			}
		}
	}
	/* Swap the pivot element with the element at (smaller_index + 1) */
	if (smaller_index + 1 != high)
	{
		temp = array[smaller_index + 1];
		array[smaller_index + 1] = array[high];
		array[high] = temp;

		print_array(array, size);
	}
	/* Return the index of pivot element after partitioning */
	return (smaller_index + 1);
}

/**
 * quick_sort_recursive - Recursive function to implement quick sort.
 *
 * @array: The array to sort.
 * @low: The lower index of the array segment.
 * @high: The higher index of the array segment.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, int size)
{
	int partition_index;

	if (low < high)
	{
		/* Get the partition index using the partition function call */
		partition_index = partition(array, low, high, size);

		/* Recursively sort the elements before and after partition */
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}
