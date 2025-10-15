#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted (starting at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	cur = *head;

	if (index == 0)
	{
		*head = cur->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(cur);
		return (1);
	}
	while (cur != NULL && i < index)
	{
		cur = cur->next;
		i++;
	}
	if (cur == NULL)
		return (-1);

	if (cur->next != NULL)
		cur->next->prev = cur->prev;
	if (cur->prev != NULL)
		cur->prev->next = cur->next;

	free(cur);
	return (1);

}
