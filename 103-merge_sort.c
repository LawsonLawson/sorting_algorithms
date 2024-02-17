#include "sort.h"


/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the merge sort algorithm.
 */
void merge_sort(int *array, size_t size);

/**
 * split_and_merge - Splits and merges the array recursively.
 *
 * @start_index: The start index of the array.
 * @end_index: The end index of the array.
 * @original_array: The original array to be sorted.
 * @working_array: A temporary array for merging.
 *
 * Description: This function splits the array into halves recursively
 * until individual elements, and then merges them in sorted order.
 */
void split_and_merge(int start_index, int end_index, int *original_array,
		int *working_array);

/**
 * merge - Merges two sorted arrays into one sorted array.
 *
 * @original_array: The original array to be sorted.
 * @mid_index: The midpoint index.
 * @end_index: The end index of the array.
 * @start_index: The start index of the array.
 * @working_array: A temporary array for merging.
 *
 * Description: This function merges two sorted subarrays into one sorted
 * array.
 */
void merge(int *original_array, size_t mid_index, size_t end_index, size_t
		start_index, int *working_array);

/**
 * copy_array - Copies the elements of one array to another.
 *
 * @destination: The destination array.
 * @source: The source array.
 * @size: The size of the arrays.
 *
 * Description: This function copies the elements of one array to another.
 */
void copy_array(int *destination, int *source, size_t size);

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *working_array;

	if (array == NULL || size < 2)
		return;

	working_array = malloc((size + 1) * sizeof(int));
	if (working_array == NULL)
		return;

	split_and_merge(0, size, array, working_array);

	free(working_array);
}

/**
 * split_and_merge - Splits and merges the array recursively.
 *
 * @start_index: The start index of the array.
 * @end_index: The end index of the array.
 * @original_array: The original array to be sorted.
 * @working_array: A temporary array for merging.
 *
 * Description: This function splits the array into halves recursively
 * until individual elements, and then merges them in sorted order.
 */
void split_and_merge(int start_index, int end_index, int *original_array,
		int *working_array)
{
	size_t mid_index = 0;

	if (end_index - start_index < 2)
		return;

	mid_index = (start_index + end_index) / 2;
	split_and_merge(start_index, mid_index, original_array, working_array);
	split_and_merge(mid_index, end_index, original_array, working_array);

	merge(original_array, mid_index, end_index, start_index,
			working_array);
}

/**
 * merge - Merges two sorted arrays into one sorted array.
 *
 * @original_array: The original array to be sorted.
 * @mid_index: The midpoint index.
 * @end_index: The end index of the array.
 * @start_index: The start index of the array.
 * @working_array: A temporary array for merging.
 *
 * Description: This function merges two sorted subarrays into one sorted
 * array.
 */
void merge(int *original_array, size_t mid_index, size_t end_index, size_t
		start_index, int *working_array)
{
	size_t left_index = start_index;
	size_t right_index = mid_index;
	size_t merged_index = 0;

	printf("Mergin...\n");
	printf("[left]: ");

	print_array(&original_array[start_index], mid_index - start_index);
	printf("[right]: ");

	print_array(&original_array[mid_index], end_index - mid_index);

	for (merged_index = start_index; merged_index <= end_index;
			merged_index++)
	{
		if (left_index < mid_index && (right_index >= end_index ||
			original_array[left_index] <= original_array[right_index]))
		{
			working_array[merged_index] = original_array[left_index];
			left_index++;
		}
		else
		{
			working_array[merged_index] = original_array[right_index];
			right_index++;
		}
	}
	copy_array(original_array, working_array, end_index);

	printf("[Done]: ");
	print_array(&original_array[start_index], end_index - start_index);
}

/**
 * copy_array - Copies the elements of one array to another.
 *
 * @destination: The destination array.
 * @source: The source array.
 * @size: The size of the arrays.
 *
 * Description: This function copies the elements of one array to another.
 */
void copy_array(int *destination, int *source, size_t size)
{
	size_t index = 0;

	for (index = 0; index <= size; index++)
	{
		destination[index] = source[index];
	}
}

