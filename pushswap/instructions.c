/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:44:44 by thelsdow          #+#    #+#             */
/*   Updated: 2026/01/26 16:44:47 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_swap(t_node **head)
{
	t_node	*newhead;
	t_node	*oldhead;

	if ((*head)->next->next == (*head))
		*head = (*head)->next;
	else
	{
		oldhead = (*head);
		newhead = oldhead->next;
		oldhead->prev->next = newhead;
		newhead->next->prev = oldhead;
		newhead->prev = oldhead->prev;
		oldhead->next = newhead->next;
		newhead->next = oldhead;
		oldhead->prev = newhead;
		(*head) = newhead;
	}
}

static void	if_pushto_null(t_node **pushto, t_node **nodetomove)
{
	if (!*pushto)
	{
		(*nodetomove)->next = (*nodetomove);
		(*nodetomove)->prev = (*nodetomove);
		*pushto = (*nodetomove);
	}
	else
	{
		(*nodetomove)->next = *pushto;
		(*nodetomove)->prev = (*pushto)->prev;
		(*pushto)->prev->next = (*nodetomove);
		(*pushto)->prev = (*nodetomove);
		*pushto = (*nodetomove);
	}
}

void	ft_push(t_node **pushfrom, t_node **pushto)
{
	t_node	*nodetomove;
	int		islast;

	if (!pushfrom || !(*pushfrom))
		return ;
	nodetomove = *pushfrom;
	islast = 0;
	if ((*pushfrom)->next == (*pushfrom))
		islast = 1;
	(*pushfrom)->prev->next = nodetomove->next;
	(*pushfrom)->next->prev = nodetomove->prev;
	*pushfrom = nodetomove->next;
	if_pushto_null(pushto, &nodetomove);
	if (islast == 1)
		(*pushfrom) = NULL;
}

void	ft_rotate(t_node **head, int move)
{
	if (move == 4 || move == 5)
		(*head) = (*head)->next;
	else
		(*head) = (*head)->prev;
}
