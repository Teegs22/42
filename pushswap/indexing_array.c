/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:01:37 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/06 13:01:44 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_if_lowest_value(t_node *current, int found, int *lowest)
{
	if (current->index == -1 && (found == 0 || (current->data < (*lowest))))
	{
		(*lowest) = current->data;
		found = 1;
	}
	return (found);
}

void	index_list(t_node **heada)
{
	t_node	*current;
	int		lowest;
	int		i;
	int		found;

	lowest = 0;
	i = 0;
	found = 1;
	while (found)
	{
		found = 0;
		current = (*heada)->next;
		while (current != (*heada))
		{
			found = check_if_lowest_value(current, found, &lowest);
			current = current->next;
		}
		if (current->index == -1)
			found = check_if_lowest_value(current, found, &lowest);
		while (found == 1 && current->data != lowest)
			current = current->next;
		if (current->data == lowest)
			current->index = i;
		i++;
	}
}
// if (found == 1)
// {
// 	while (current->data != lowest)
// 		current = current->next;
// 	current->index = i;
// }
// i++;
