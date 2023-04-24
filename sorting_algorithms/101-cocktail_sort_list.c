#include "sort.h"
/**
 * cocktail_sort_list -  a function that sorts a doubly linked
 * list of integers in ascending order using the Cocktail shaker
 * sort algorithm
 * @list: list to be sorted 
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = *list;
	listint_t *end = NULL;
	listint_t *i;

	int swapped = 1;

	while (swapped)
	{
		swapped = 0;
		for (i = start; i->next != end; i = i->next)
		{
			if (i->n > i->next->n)
			{
				swapNodes(list, i, i->next);
				print_list(*list);
				break;
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		end = i;
		for (i = end; i->prev != start; i = i->prev)
		{
			if (i->n < i->prev->n)
			{
				swapNodes(list, i, i->prev);
				print_list(*list);
				swapped = 1;
			}
		}
		start = i;
	}
}

void swapNodes(listint_t **list, listint_t *node1, listint_t *node2) 
{
	
	listint_t *temp;
    /*Check if either node is the head*/
    if (*list == node1) {
        *list = node2;
    } else if (*list == node2) {
        *list = node1;
    }

    /*Swap the prev pointers*/
    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    /*Swap the next pointers*/
    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    /*Update the adjacent nodes' pointers*/
    if (node1->prev != NULL) {
        node1->prev->next = node2;
    }
    if (node1->next != NULL) {
        node1->next->prev = node2;
    }
    if (node2->prev != NULL) {
        node2->prev->next = node1;
    }
    if (node2->next != NULL) {
        node2->next->prev = node1;
    }
}
