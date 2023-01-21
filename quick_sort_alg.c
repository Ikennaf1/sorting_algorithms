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
}
