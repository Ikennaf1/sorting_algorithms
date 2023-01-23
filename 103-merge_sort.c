#include "sort.h"

/**
 * merge - Merges two arrays
 * @array: Given array
 * @left: Left array
 * @right: Right array
 * @ub: Upper bound
 * Return: Nothing
 */
void merge(__attribute__((unused))int *array, int *left, int *right, __attribute__((unused)) int ub)
{
	int i = 0, j = 0, k = 0;
	/*printf("left: %d\n", left[i]);*/

	while (i < ub)
	/*while (left[j] || right[k])*/
	{
		if (left[j]/* && left[j] <= right[k]*/)
		{
			/*printf("Left: %d\n", left[j]);*/
			/*array[i] = left[j];*/
			j++;
		}
		else
		{
			if (right[k])
			{
				/*printf("Right: %d\n", right[k]);*/
				/*array[i] = right[k];*/
				k++;
			}
		}
		i++;
	}
}

/**
 * merge_sort_alg - The merge sort algorithm
 * @array: given array
 * @lb: Lower bound
 * @ub: Upper bound
 * Return: Nothing
 */
void merge_sort_alg(int *array, int lb, int ub)
{
	int i, j, mid, *left = NULL, *right = NULL, *new_array = NULL;

	if (ub > 1)
	{
		mid  = (lb + ub) / 2;

		left = (int *) malloc(sizeof(int) * mid);
		if (left == NULL)
			return;
		right = (int *) malloc(sizeof(int) * (ub - mid));
		if (right == NULL)
			return;
		new_array = (int *) malloc(sizeof(int) * ub);
		if (new_array == NULL)
			return;

		for (i = 0; i < mid; i++)
			left[i] = array[i];
		printf("left - lb: %d lb-index: %d ub: %d ub-index: %d\n", left[lb], lb, left[mid - 1], mid - 1);
		for (i = mid, j = 0; i < ub; i++, j++)
			right[j] = array[i];
		printf("Right - lb: %d lb-index: %d ub: %d ub-index: %d\n\n", right[lb], mid, right[ub - 1], ub - 1);

		merge_sort_alg(left, lb, mid);
		merge_sort_alg(right, mid, ub);
		/*merge(array, left, right, ub);*/
	}
	merge(new_array, left, right, ub);
	/*free(array);*/
	/*array = new_array;*/
	free(left);
	free(right);
	return;
}

/**
 * merge_sort - Sorts an array using Merge sort algorithm
 * @array: Given array
 * @size: Size of array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int a_size = size;

	if (array == NULL || size < 2)
		return;
	merge_sort_alg(array, 0, a_size);
}
