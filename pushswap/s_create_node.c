/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_create_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:19:26 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/10 12:19:28 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*s_create_node(int *value, int **arrmoves)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free(value);
		free(arrmoves);
		error();
	}
	new_node->data = (*value);
	new_node->next = new_node;
	new_node->prev = new_node;
	new_node->index = -1;
	return (new_node);
}
