#include "sort.h"
void cocktail_sort_list(listint_t **list);
/**
 * swap_left - Performs a leftward swap operation on a node in a linked list.
 * @wnode: Node to be swapped.
 * @list: Pointer to the head of the linked list.
 */
void swap_left(listint_t *wnode, listint_t **list)
{
	listint_t *min = wnode, *nodeprev, *minnext, *node;

	while (min->prev != NULL && min->prev->n > min->n)
	{
		minnext = min->next;
		node = min->prev;
		nodeprev = node->prev;

		if (minnext != NULL)
			minnext->prev = node;
		node->next = minnext;
		node->prev = min;

		min->next = node;
		min->prev = nodeprev;

		if (nodeprev != NULL)
			nodeprev->next = min;
		else
			*list = min;
		print_list(*list);
	}
}

/**
 * swap_right - Performs a rightward swap operation on a node in a linked list.
 * @wnode: Node to be swapped.
 * @list: Pointer to the head of the linked list.
 */
void swap_right(listint_t *wnode, listint_t **list)
{
	listint_t *maxprev, *max = wnode, *node, *nodenext;

	while (max->next != NULL && max->n > max->next->n)
	{
		node = max->next;
		nodenext = node->next;
		maxprev = max->prev;
		if (nodenext != NULL)
			nodenext->prev = max;

		max->prev = node;
		max->next = nodenext;

		node->prev = maxprev;
		node->next = max;

		if (maxprev != NULL)
			maxprev->next = node;
		else
			*list = node;
		print_list(*list);
	}
}
/**
 * cocktail_sort_list - Sorts a doubly
 * linked list using the cocktail sort algorithm.
 * @list: Pointer to the head of the linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_direction = 1;

	int pass_swap_flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (1)
	{
		pass_swap_flag = 0;

		if (swap_direction == 1)
		{
			node = *list;
			while (node->next != NULL)
			{
				if (node->next->n < node->n)
				{
					swap_right(node, list);
					pass_swap_flag = 1;
				}
				if (node->next == NULL)
				{
					swap_direction = 0;
					break;
				}
				node = node->next;
			}
		}
		else
		{
			while (node->prev != NULL)
			{
				if (node->prev->n > node->n)
				{
					swap_left(node, list);
					pass_swap_flag = 1;
				}
				if (node->prev == NULL)
				{
					swap_direction = 1;
					break;
				}

				node = node->prev;
			}
			swap_direction = 1;
		}
		if (!pass_swap_flag)
			break;
	}
}
