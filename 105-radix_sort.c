#include "sort.h"

/**
 * find_maximum - Finds the maximum value in an array of integers.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: (int) The maximum integer in the array.
 */
int find_maximum(int *array, int size);

/**
 * sort_significant_digits - Sorts the significant digits of an array of
 * integers in ascending order.
 *
 * Description: This function implements the counting sort algorithm to sort
 * the significant digits of an array of integers in ascending order.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @digit_position: The position of the significant digit to sort on.
 * @temp_buffer: A buffer to store the sorted array temporarily.
 */
void sort_significant_digits(int *array, size_t size, int digit_position,
		int *temp_buffer);

/**
 * radix_sort - Sorts an array of integers in ascending order using the radix
 * sort algorithm.
 *
 * Description: This function implements the Least Significant Digit (LSD)
 * radix sort algorithm. It sorts an array of integers in ascending order and
 * prints the array after each significant digit increase.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size);

/**
 * find_maximum - Finds the maximum value in an array of integers.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: (int) The maximum integer in the array.
 */
int find_maximum(int *array, int size)
{
	int maximum = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * sort_significant_digits - Sorts the significant digits of an array of
 * integers in ascending order.
 *
 * Description: This function implements the counting sort algorithm to sort
 * the significant digits of an array of integers in ascending order.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @digit_position: The position of the significant digit to sort on.
 * @temp_buffer: A buffer to store the sorted array temporarily.
 */
void sort_significant_digits(int *array, size_t size, int digit_position,
		int *temp_buffer)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit_position) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		temp_buffer[count[(array[i] / digit_position) % 10] - 1]
			= array[i];
		count[(array[i] / digit_position) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = temp_buffer[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the radix
 * sort algorithm.
 *
 * Description: This function implements the Least Significant Digit (LSD)
 * radix sort algorithm. It sorts an array of integers in ascending order and
 * prints the array after each significant digit increase.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, digit_position, *temp_buffer;

	if (array == NULL || size < 2)
		return;

	temp_buffer = malloc(sizeof(int) * size);
	if (temp_buffer == NULL)
		return;

	maximum = find_maximum(array, size);
	for (digit_position = 1; maximum / digit_position > 0; digit_position
			*= 10)
	{
		sort_significant_digits(array, size, digit_position,
				temp_buffer);
		print_array(array, size);
	}

	free(temp_buffer);
}
