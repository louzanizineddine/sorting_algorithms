#include "sort.h"

/**
 * swap - function to swap tow elemnt in array
 *
 * @a: the first ilment
 * @b: the elemet to swap with
 *
 * Return: fucntion has no return value
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort - implementation quick sort algorithm
 *
 * @array: input array
 * @size: size of the array
 *
 * Return: FUNCTION DO NOT RETURN
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	Quick_sort(array, 0, size - 1, size);
}

/**
 * Quick_sort - implementation quick sort algorithm
 *
 * @array: input array
 * @size: size of the array
 * @high: last index of the array
 * @low: frist index of the array
 *
 * Return: FUNCTION DO NOT RETURN value
 */

void Quick_sort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (array == NULL)
		return;
	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		Quick_sort(array, low, pivot_index - 1, size);
		Quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - implementation lomuto_partition scheme
 *
 * @array: input array
 * @high: last index of the array
 * @low: frist index of the array
 * @size: size of the array
 *
 * Return: index for the new pivot elment
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	if (!array || low >= high || low < 0 || high < 0)
		return (-1);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
