#include "sort.h"

/**
 * shell_sort - Sorts an array using shell sort
 * @array: The given array
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	int /*lb, ub,*/ temp, i, j, gap = 1, a_size = size;

	if (array == NULL || size < 2)
		return;

	while (gap < (a_size / 3))
		gap = gap * 3 + 1;

	for (; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < a_size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[i])
				{
					break;
				}
				else
				{
					temp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = temp;
					/*print_array(array, size);*/
				}
			}
		}
		print_array(array, size);
	}
}
