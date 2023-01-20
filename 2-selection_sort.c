#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort
 * @array: given array
 * @size: Size of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int smallest, swapped = 0;
	unsigned int index, i, j;

	if (array == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				index = j;
			}
		}
		if (smallest < array[i])
		{
			array[index] = array[i];
			array[i] = smallest;
			print_array(array, size);
			swapped++;
		}
	}
}
