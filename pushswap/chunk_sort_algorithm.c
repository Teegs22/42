/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:01:13 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/06 13:01:15 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static int	push_b_rotate(t_node **heada, t_node **headb, int **a, int lena)
// {
// 	int	total;
// 	int	i;

// 	i = lena - 5;
// 	if (i < 0)
// 		i = 0;
// 	total = 0;
// 	if ((*heada)->index >= i && (*heada)->index < lena)
// 	{
// 		sort_which_move(PB, a, heada, headb);
// 		total ++;
// 	}
// 	else
// 		sort_which_move(RA, a, heada, headb);
// 	return (total);
// }

// static void	reverse_b_push_a(t_node **heada, t_node **headb, int **arrmoves)
// {
// 	while ((*headb)->next->index != (*heada)->index - 1)
// 		sort_which_move(RB, arrmoves, heada, headb);
// 	sort_which_move(SB, arrmoves, heada, headb);
// 	sort_which_move(PA, arrmoves, heada, headb);
// }

// static void	reverse_b_push_a(t_node **heada, t_node **headb, int **arrmoves)
// {
// 	int		i;
// 	int		len;
// 	t_node	*current;

// 	len = 0;
// 	i = 0;
// 	current = (*headb);
// 	if ((*headb)->index == (*heada)->index - 1)
// 		sort_which_move(PA, arrmoves, heada, headb);
// 	else
// 	{
// 		current = (*headb) -> next;

// 	}



// 	while ((*headb)->next->index != (*heada)->index - 1)
// 		sort_which_move(RB, arrmoves, heada, headb);
// 	sort_which_move(SB, arrmoves, heada, headb);
// 	sort_which_move(PA, arrmoves, heada, headb);
// }

// void	ft_chunk_sort_to_b(int **a, t_node **heada, t_node **headb, int lena)
// {
// 	int		i;
// 	int		total_pushed;
// 	t_node	*originhead;

// 	i = lena;
// 	while (i > 0)
// 	{
// 		i = i - 5;
// 		if (i < 0)
// 			i = 0;
// 		total_pushed = 0;
// 		while ((*heada)->index >= i && (*heada)->index < lena)
// 			push_b_rotate(heada, headb, a, lena);
// 		if (lena - i != total_pushed)
// 		{
// 			originhead = (*heada);
// 			sort_which_move(RA, a, heada, headb);
// 			while ((*heada) != originhead && total_pushed != lena - i)
// 				total_pushed += push_b_rotate(heada, headb, a, lena);
// 		}
// 		lena = i;
// 	}
// }


void	ft_chunk_sort_to_b(int **a, t_node **heada, t_node **headb, int lena)
{
	int		num;
	int		total_pushed;
	int		section;
	// t_node	*originhead;

	if (lena <= 7)
		section = lena;
	else 
		section = lena / 5;
	num = 0;
	while (1)
	{
		if (num >= lena)
			break;
		num = num + section;
		if (lena - num < section)
		{
			section = section + (lena - num);
			num = lena;
		}
		total_pushed = 0;
		while (total_pushed != section)
		{
			while (total_pushed != section && (*heada)->index < num)
			{
				if ((*heada)->next->index < (*heada)->index)
				{
					sort_which_move(SA, a, heada, headb);
					if ((*headb) && (*headb)->index < (*headb)->next->index)
						sort_which_move(SB, a, heada, headb);
				}
				if ((*heada)->prev->index < (*heada)->index)
				{
					sort_which_move(RRA, a, heada, headb);
					if ((*headb) && (*headb)->index < (*headb)->prev->index)
						sort_which_move(RRB, a, heada, headb);
				}
				else if ((*heada)->index < num)
				{
					sort_which_move(PB, a, heada, headb);
					total_pushed ++;
				}
			}
			if ((*heada)->prev->index < num)
				sort_which_move(RRA, a, heada, headb);
			else
				sort_which_move(RA, a, heada, headb);
		}
	}
}

// void	ft_chunk_sort_to_a(int **arrmoves, t_node **heada, t_node **headb)
// {
// 	int		i;
// 	int		len;
// 	t_node	*current;

// 	while (headb && (*headb))
// 	{
// 		len = 1;
// 		current = (*headb)->next;
// 		i = 0;
// 		while (current != (*headb))
// 		{
// 			if (current->index > i)
// 				i = len - 1;
// 			current = current->next;
// 			len++;
// 		}
// 		if (i <= len % 2)
// 			reverse_b_push_a(heada, headb, arrmoves);
// 		else
// 		{
// 			while ((*headb)->index != (*heada)->index - 1)
// 				sort_which_move(RRB, arrmoves, heada, headb);
// 			sort_which_move(PA, arrmoves, heada, headb);
// 		}
// 	}
// }

void	ft_chunk_sort_to_a(int **arrmoves, t_node **heada, t_node **headb)
{
	int		i;
	int		len;
	int		max;
	t_node	*current;

	while ((*heada)->index != 0)
	{
		i = 0;
		len = 1;
		current = (*headb)->next;
		if ((*headb)->index == (*heada)->index - 1)
			sort_which_move(PA, arrmoves, heada, headb);
		else
		{
			while (current != (*headb))
			{
				if (current->index == (*heada)->index - 1)
				{
					max = current->index;
					i = len - 1;
				}
				current = current->next;
				len++;
			}
			while (i > len / 2 && (*heada)->index != max)
			{
				if ((*headb)->index >= max - 2)
					sort_which_move(PA, arrmoves, heada, headb);
				sort_which_move(RRB, arrmoves, heada, headb);
			}
			while (i <= len / 2 && (*heada)->index != max)
			{
				if ((*headb)->index >= max - 1)
					sort_which_move(PA, arrmoves, heada, headb);
				sort_which_move(RB, arrmoves, heada, headb);
				if ((*headb)->next->index == max)
				{
					sort_which_move(SB, arrmoves, heada, headb);
					sort_which_move(PA, arrmoves, heada, headb);
					break ;
				}
			}
			if ((*heada)->index > (*heada)->next->index)
				sort_which_move(SA, arrmoves, heada, headb);
		}
	}
}
