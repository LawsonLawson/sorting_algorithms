#include "sort.h"


/**
 * bitonic_sort - Sorts an array of integers using the bitonic sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * This function sorts the given array in ascending order using the
 * bitonic sort algorithm.
 * It first constructs a bitonic sequence and then recursively
 * performs bitonic merge operations to sort the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	/* Construct a bitonic sequence */
	bitonic_seq(array, size, size, 0);
}


/**
 * bitonic_seq - Constructs a bitonic sequence for a given array.
 * @array: Pointer to the array to construct the bitonic sequence.
 * @size: Size of the array.
 * @seq: Size of the bitonic sequence.
 * @flow: Merging direction (0 for ascending, 1 for descending).
 *
 * This function recursively constructs a bitonic sequence for the given array.
 * It divides the array into two halves, recursively constructs bitonic
 * sequences for each half, performs bitonic merge, and prints
 * the intermediate results.
 */
void bitonic_seq(int *array, size_t size, size_t seq, char flow)
{
	int mid = size / 2;

	printf("Merging [%lu/%lu] (%s):\n", size, seq, flow ? "DOWN" : "UP");
	print_array(array, size);

	if (size <= 2)
	{
		printf("Result [%lu/%lu] (%s):\n", size, seq, flow ? "DOWN" : "UP");
		if ((array[0] < array[1]) == flow)
			swap(&array[0], &array[1]);

		print_array(array, size);
		return;
	}

	bitonic_seq(array, mid, seq, 0);
	bitonic_seq(array + mid, mid, seq, 1);

	bitonic_merge(array, mid, size, flow);

	printf("Result [%lu/%lu] (%s):\n", size, seq, flow ? "DOWN" : "UP");
	print_array(array, size);
}


/**
 * bitonic_merge - Merges two subsequences of an array in bitonic order.
 * @array: Pointer to the array to be merged.
 * @size: Size of the array.
 * @seq: Size of the subsequence to be merged.
 * @flow: Merging direction (0 for ascending, 1 for descending).
 *
 * This function merges two subsequences of the array in bitonic order based on
 * the specified merging direction. It iterates through the elements of the
 * sequence, comparing and swapping elements as necessary.
 * The 'flow' parameter determines whether the merge is in ascending or
 * descending order. It also recursively calls itself to continue the merge
 * process until the base case is reached (size == 1).
 */
void bitonic_merge(int *array, size_t size, size_t seq, char flow)
{
	size_t i;

	for (i = 0; i < seq; i++)
	{
		if (i + size >= seq)
			break;

		/* Compare and swap elements based on the specified flow */
		if ((array[i] < array[i + size]) == flow)
			swap(&array[i], &array[i + size]);
	}

	if (size == 1)
		return;

	/* Recursively perform bitonic merge on the smaller subsequence */
	bitonic_merge(array, size / 2, seq, flow);
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
