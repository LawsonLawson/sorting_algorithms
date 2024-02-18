#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers using the Hoare
 * partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the given array in ascending order
 * using the quicksort algorithm with the Hoare partition scheme.
 * It first checks for edge cases, such as a NULL array or an array with
 * less than 2 elements, and returns if needed.
 * Then, it calls the _quicksort function to perform the actual sorting.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quicksort(array, size, 0, size - 1, size);
}

/**
 * _quicksort - Recursive function to implement the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @left: Index of the leftmost element.
 * @right: Index of the rightmost element.
 * @part_idx: Index of the partition element from the previous partitioning.
 *
 * This function implements the quicksort algorithm using recursion. It
 * selects a pivot, partitions the array, and recursively applies quicksort
 * to the subarrays on either side of the pivot. It maintains the index of the
 * partition element from the previous partitioning to optimize the
 * sorting process.
 *
 */
void _quicksort(int *array, int size, int left, int right, int part_idx)
{
	int new_part_idx;

	if (left < right)
	{
		new_part_idx = partition(array, size, left, right);

		/* Update part_idx based on the new partition index */
		if (part_idx == new_part_idx)
			part_idx = new_part_idx - 1;
		else
			part_idx = new_part_idx;

		/* Recursively apply quicksort to the subarrays */
		_quicksort(array, size, left, part_idx, new_part_idx);
		_quicksort(array, size, part_idx + 1, right, new_part_idx);
	}

}

/**
 * partition - Partitions an array using the Lomuto partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * @left: Index of the leftmost element in the partition range.
 * @right: Index of the rightmost element in the partition range.
 *
 * Description: This function partitions the array using the Lomuto
 * partition scheme.
 * It selects the pivot as the rightmost element, rearranges the array elements
 * in such a way that elements smaller than the pivot are on the left, and
 * elements greater than the pivot are on the right. The index of the pivot
 * after partitioning is returned.
 *
 * Return: the index of the pivot after partitioning.
 */
int partition(int *array, int size, int left, int right)
{
	int pivot, i, j;

	pivot = array[right];
	i = left - 1;
	j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		/* Swap elements at indices i and j */
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}


/**
 * swap - Swaps the values of two integers using XOR swap algorithm.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 *
 * Description: This function takes two integer pointers and swaps
 * the values they point to using the XOR swap algorithm,
 * a technique to swap values without using a temporary variable.
 */
void swap(int *x, int *y)
{
	/* Check if either pointer is NULL */
	if (!x || !y)
		return;

	/* Check if the values pointed by x and y are different */
	if (*x != *y)
	{
		/* XOR swap algorithm */
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}
