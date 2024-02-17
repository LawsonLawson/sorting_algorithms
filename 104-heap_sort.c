#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * This function implements the heap sort algorithm to sort the given array
 * in ascending order. It first builds a max-heap, then repeatedly extracts
 * the maximum element from the heap and places it at the end of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i, j;

	/* Build a max-heap by repeatedly calling sift_down */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, i, size, size);

	/* print_array(array, size); */
	/* Extract elements from the heap and place them at the end of the array */
	for (j = size - 1; j > 0; j--)
	{
		/* Swap the root (maximum element) with the last element */
		swap(&array[0], &array[j]);
		print_array(array, size);

		/* Restore the max-heap property after the swap */
		sift_down(array, 0, size, j);
	}
}

/**
 * sift_down - Performs a sift down operation on a binary heap.
 * @array: Pointer to the array representing the binary heap.
 * @root: Index of the root element.
 * @size: Size of the heap.
 * @base: The base index beyond which elements are not considered.
 *
 * This function sifts down the element at the given root index in the
 * binary heap to maintain the max-heap property. It recursively swaps the root
 * with its larger child until the heap property is restored.
 * The 'base' parameter limits the consideration of elements,
 * ensuring that only elements up to that index are checked.
 */
void sift_down(int *array, size_t root, size_t size, size_t base)
{
	/* Calculate indices of left and right children */
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	/* let's assume the root is the largest */
	size_t largest = root;

	/* check if left child exists and is larger than the root */
	if (left < base && array[left] > array[largest])
		largest = left;

	/* Check if right child exists and is larger than the root */
	if (right < base && array[right] > array[largest])
		largest = right;

	/**
	 * If the largest element is not the root,
	 * swap and recursively sift down
	 */
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, largest, size, base); /* recursively sift down */
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

