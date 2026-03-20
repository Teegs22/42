/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:07:54 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/10 15:07:55 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	find_smallest_and_largest(t_node *heada, int *smallest, int *largest)
{
	t_node	*current;

	current = heada->next;
	while (current != heada)
	{
		if (current->index > (*largest))
			(*largest) = current->index;
		if (current->index < (*smallest))
			(*smallest) = current->index;
		current = current->next;
	}
	if (current->index > (*largest))
		(*largest) = current->index;
	if (current->index < (*smallest))
		(*smallest) = current->index;
}

void	reverse_one_way(t_node **heada, int **arrmoves,
			t_node **headb, int smallest)
{
	if ((*heada)->next->index == smallest)
		sort_which_move(RA, arrmoves, heada, headb);
	while ((*heada)->index != smallest)
		sort_which_move(RRA, arrmoves, heada, headb);
}

void	reassign_arrmoves(int **arrmoves, int **temp, int move)
{
	int	i;

	i = -1;
	while ((*arrmoves)[++i] != -1)
		(*temp)[i] = (*arrmoves)[i];
	(*temp)[i] = -1;
	free (*arrmoves);
	*arrmoves = NULL;
	i = 0;
	while ((*temp)[i] != -1)
		i++;
	(*arrmoves) = malloc(sizeof(int) * (i + 2));
	if (!*arrmoves)
		return ;
	i = -1;
	while ((*temp)[++i] != -1)
		(*arrmoves)[i] = (*temp)[i];
	(*arrmoves)[i] = move;
	(*arrmoves)[i + 1] = -1;
	free(*temp);
}

void	work_out_which_func(int lena, int **arrmoves,
		t_node **heada, t_node **headb)
{
	if (lena == 2)
		sort_two_element_array(arrmoves, heada, headb);
	else if (lena == 3)
		sort_three_element_array(arrmoves, heada, headb);
	else if (lena == 4)
		sort_four_element_array(arrmoves, heada, headb, 1);
	else if (lena == 5)
		sort_five_element_array(arrmoves, heada, headb);
	else
	{
		ft_chunk_sort_to_b(arrmoves, heada, headb, lena - 5);
		sort_five_element_array(arrmoves, heada, headb);
		ft_chunk_sort_to_a(arrmoves, heada, headb);
	}
}
