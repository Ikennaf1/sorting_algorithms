#include "sort.h"

/**
 * insertion_sort_list - Sorts doubly linked list using insertion sort
 * @list: The list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *sorted_node = NULL;
	int temp, *sorted_temp = NULL, *tmp, next_temp;

	if (list == NULL || *list == NULL)
		exit(EXIT_FAILURE);

	for (node = (*list)->next; node != NULL; node = node->next)
	{
		if (node == NULL)
			return;
		sorted_node = node->prev;
		temp = node->n;

		while (sorted_node->prev != NULL && sorted_node->n > temp)
		{
			sorted_temp = (int *) &(sorted_node->next->n);
			tmp = (int *) &(sorted_node->n);
			next_temp = sorted_node->next->n;
			*sorted_temp = sorted_node->n;
			*tmp = next_temp;
			sorted_node = sorted_node->prev;
			print_list(*list);
		}
		if (sorted_node->prev == NULL && sorted_node->n > temp)
		{
			sorted_temp = (int *) &(sorted_node->next->n);
			*sorted_temp = sorted_node->n;
			sorted_temp = (int *) &(sorted_node->n);
			*sorted_temp = temp;
			print_list(*list);
		}
		else
		{
			sorted_temp = (int *) &(sorted_node->next->n);
			*sorted_temp = temp;
		}
	}
}
