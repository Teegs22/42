/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:54:20 by thelsdow          #+#    #+#             */
/*   Updated: 2026/01/26 16:54:23 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	sort_two_element_array(int **arrmoves, t_node **heada, t_node **headb)
{
	if ((*heada)->data > (*heada)->next->data)
		sort_which_move(SA, arrmoves, heada, headb);
}

void	sort_three_element_array(int **arrmoves, t_node **heada, t_node **headb)
{
	if ((*heada)->data > (*heada)->next->data)
	{
		if ((*heada)->data > (*heada)->prev->data)
			sort_which_move(RA, arrmoves, heada, headb);
		else
			sort_which_move(SA, arrmoves, heada, headb);
		if ((*heada)->data > (*heada)->next->data)
			sort_which_move(SA, arrmoves, heada, headb);
	}
	else
	{
		if ((*heada)->data < (*heada)->prev->data
			&& (*heada)->next->data < (*heada)->prev->data)
			return ;
		sort_which_move(RRA, arrmoves, heada, headb);
		if ((*heada)->data > (*heada)->next->data)
			sort_which_move(SA, arrmoves, heada, headb);
	}
}

void	sort_four_element_array(int **arrmoves,
								t_node **heada, t_node **headb, int onlyfour)
{
	sort_which_move(PB, arrmoves, heada, headb);
	sort_three_element_array(arrmoves, heada, headb);
	if ((*headb)->data < (*heada)->next->data
		&& (*headb)->data > (*heada)->data)
		sort_which_move(RA, arrmoves, heada, headb);
	else if ((*headb)->data < (*heada)->prev->data
		&& (*headb)->data > (*heada)->data)
		sort_which_move(RRA, arrmoves, heada, headb);
	sort_which_move(PA, arrmoves, heada, headb);
	if (onlyfour == 1)
	{
		if ((*heada)->data > (*heada)->next->data)
			sort_which_move(RA, arrmoves, heada, headb);
		while ((*heada)->data > (*heada)->prev->data)
			sort_which_move(RRA, arrmoves, heada, headb);
	}
}

void	sort_five_element_array(int **arrmoves, t_node **heada, t_node **headb)
{
	int		smallest;
	int		largest;

	sort_which_move(PB, arrmoves, heada, headb);
	sort_four_element_array(arrmoves, heada, headb, 0);
	smallest = (*headb)->index;
	largest = (*headb)->index;
	find_smallest_and_largest((*heada), &smallest, &largest);
	if ((*headb)->index == largest)
	{
		reverse_one_way(heada, arrmoves, headb, smallest);
		sort_which_move(PA, arrmoves, heada, headb);
		sort_which_move(RA, arrmoves, heada, headb);
		return ;
	}
	reverse_one_way(heada, arrmoves, headb, ((*headb)->index) + 1);
	sort_which_move(PA, arrmoves, heada, headb);
	if ((*heada)->prev->index == smallest
		|| (*heada)->prev->prev->index == smallest)
	{
		sort_which_move(RRA, arrmoves, heada, headb);
		if ((*heada)->prev->index == smallest)
			sort_which_move(RRA, arrmoves, heada, headb);
	}
	if ((*heada)->index != smallest)
		sort_which_move(RA, arrmoves, heada, headb);
}
