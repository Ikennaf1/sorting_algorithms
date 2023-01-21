#include "sort.h"

/**
 * partition - Partitions for a quick sort
 * @array: Given array
 * @lb: Lower bound
 * @ub: Upper bound
 * Return: Index location of partition
 */
unsigned int partition(int *array, int lb, int ub, size_t size)
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
			print_array(array, size);
		}
	}
	temp = array[lb];
	array[lb] = array[end];
	array[end] = temp;

	return (end);
}
