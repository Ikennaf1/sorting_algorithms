#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble sort
 * @array: The given array
 * @size: Size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp, flag = 0, pass = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - pass - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag++;
				print_array(array, size);
			}
		}
		pass++;
		if (flag == 0)
			break;
	}
}
