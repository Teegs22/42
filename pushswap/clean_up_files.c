/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:47 by thelsdow          #+#    #+#             */
/*   Updated: 2026/01/26 16:55:52 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	end_program(t_node **heada, int **arrmoves)
{
	int					i;
	static const char	*g_move_names[8] = {"sa", "sb", "pa",
		"pb", "ra", "rb", "rra", "rrb"};

	free_list(heada);
	// free(heada)
	i = 0;
	while ((*arrmoves)[i] != -1)
	{
		if ((*arrmoves)[i + 1] == -1)
		{
			if ((*arrmoves)[i] == 7 || (*arrmoves)[i] == 6)
				write(1, g_move_names[(*arrmoves)[i]], 3);
			else
			{
				write(1, g_move_names[(*arrmoves)[i]], 2);
				i++;
			}
			write(1, "\n", 1);
			break ;
		}
		i = compare_and_print((*arrmoves), i);
	}
	free(*arrmoves);
}

static int	write_move(int num, int i)
{
	static const char	*g_move_names[8] = {"sa", "sb", "pa",
		"pb", "ra", "rb", "rra", "rrb"};

	if (num == 6 || num == 7)
	{
		write(1, g_move_names[num], 3);
		i --;
	}
	else
	{
		write(1, g_move_names[num], 2);
		i --;
	}
	return (i);
}

int	compare_and_print(int *arrmoves, int i)
{
	int	skip;
	int	num;
	int	next_num;

	num = arrmoves[i];
	next_num = arrmoves[i + 1];
	skip = 0;
	if ((num == 2 && next_num == 3) || (num == 3 && next_num == 2)
		|| (num == 4 && next_num == 5) || (num == 5 && next_num == 4)
		|| (num == 6 && next_num == 7) || (num == 7 && next_num == 6))
		skip = 1;
	else if ((num == 0 && next_num == 1) || (num == 1 && next_num == 0))
		write(1, "ss", 2);
	else if ((num == 4 && next_num == 5) || (num == 5 && next_num == 4))
		write(1, "rr", 2);
	else if ((num == 6 && next_num == 7) || (num == 7 && next_num == 6))
		write(1, "rrr", 3);
	else
		i = write_move(num, i);
	if (skip == 0)
		write(1, "\n", 1);
	i += 2;
	return (i);
}

void	free_list(t_node **heada)
{
	t_node	*current;
	t_node	*next;

	if (!heada || !*heada)
		return ;
	current = (*heada)->next;
	while (current != (*heada))
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*heada);
	*heada = NULL;
}
