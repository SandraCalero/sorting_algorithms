#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list to be sorted
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *position = NULL;
	listint_t *current = NULL;

	int flag = 0;

	if (*list == NULL || (*list)->next == NULL)
		return;
	for (position = *list ; position != NULL ; position = position->next)
	{
		current = position;
		flag = 0;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			if (position->prev != NULL && flag == 0)
			{
				position = position->prev;
				flag = 1;
			}
			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			current->prev->next = current->next;
			if (current->prev->prev != NULL)
			{
				current->prev->prev->next = current;
			}
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
	}
}
