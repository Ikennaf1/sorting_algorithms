#include "sort.h"

/**
 * quick_sort_alg - A quick sorting algorithm
 * @array: Given array
 * @lb: Lower bound
 * @ub: Upper bound
 * @size: Size of array
 * Return: Nothing
 */
void quick_sort_alg(int *array, int lb, int ub, size_t size)
{
	int loc = 0;

	if (lb < ub)
	{
		loc = partition (array, lb, ub, size);
		quick_sort_alg(array, lb, loc - 1, size);
		quick_sort_alg(array, loc + 1, ub, size);
	}
	if (array[lb] < array[ub])
		print_array(array, size);
}

/**
 * partition - Partitions for a quick sort
 * @array: Given array
 * @lb: Lower bound
 * @ub: Upper bound
 * Return: Index location of partition
 */
unsigned int partition(int *array, int lb, int ub, __attribute__((unused)) size_t size)
{
	int pivot = array[lb], temp;
	int start = lb, end = ub;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;

		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}
	}
	temp = array[lb];
	array[lb] = array[end];
	array[end] = temp;

	return (end);
}

/**
 * quick_sort - Sorts an array using quick sort
 * @array: Given array
 * @size: Size of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_alg(array, 0, size - 1, size);
}
