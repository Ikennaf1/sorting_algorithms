#include "sort.h"

/**
 * counting_sort - Sorts an array using Counting sorting algorithm
 * @array: Given array
 * @size: Size of array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int a, i, j, k, a_size = size, *count = NULL;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (i = 1; i < a_size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	k++;

	count = (int *) malloc(sizeof(int) * k);
	if (count == NULL)
		return;

	for (i = 0; i < k; i++)
		count[i] = 0;
	for (i = 0; i < a_size; i++)
		count[array[i]] = 1;
	for ( i = 0, j = 0; i < k; i++)
	{
		if (count[i] > 0)
			j++;
		count[i] = j;
	}
	print_array(count, k);
	for (i = 0, j = 0, a = 0; i < k; i++)
	{
		if (count[i] == j)
		{
			a++;
		}
		else
		{
			array[j] = a++;
			j++;
		}
	}
}
