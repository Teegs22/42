/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:45:12 by thelsdow          #+#    #+#             */
/*   Updated: 2026/01/26 16:45:14 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_is_int(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (ft_atoi(str) < INT_MIN || ft_atoi(str) > INT_MAX)
		return (0);
	return (1);
}

void	sort_which_move(int move, int **arrmoves,
						t_node **heada, t_node **headb)
{
	if (move == 0)
		ft_swap(heada);
	else if (move == 1)
		ft_swap(headb);
	else if (move == 2)
		ft_push(headb, heada);
	else if (move == 3)
		ft_push(heada, headb);
	else if (move == 4)
		ft_rotate(heada, move);
	else if (move == 5)
		ft_rotate(headb, move);
	else if (move == 6)
		ft_rotate(heada, move);
	else if (move == 7)
		ft_rotate(headb, move);
	add_move_to_list(move, arrmoves);
}

void	add_move_to_list(int move, int **arrmoves)
{
	int	*temp;
	int	i;

	if ((*arrmoves)[0] == -1)
	{
		free(*arrmoves);
		(*arrmoves) = malloc(sizeof(int) * 2);
		if (!*arrmoves)
			return ;
		(*arrmoves)[0] = move;
		(*arrmoves)[1] = -1;
	}
	else
	{
		i = 0;
		while ((*arrmoves)[i] != -1)
			i++;
		temp = malloc(sizeof(int) * (i + 1));
		if (!temp)
			return ;
		reassign_arrmoves(arrmoves, &temp, move);
	}
	write(1, "added", 5);
}

void	add_new_node_front(t_node **head, int *data, int **arrmoves)
{
	t_node	*new;
	t_node	*tail;

	new = s_create_node(data, arrmoves);
	if (!head)
		end_program(head, arrmoves);
	if (!*head)
	{
		*head = new;
		return ;
	}
	tail = (*head)->prev;
	new->next = *head;
	new->prev = tail;
	tail->next = new;
	(*head)->prev = new;
	*head = new;
}

int	main(int argc, char **argv)
{
	int		lena;
	int		*arrmoves;
	t_node	*heada;
	t_node	*headb;

	lena = 0;
	arrmoves = malloc(sizeof(int));
	if (!arrmoves)
		error();
	arrmoves[0] = -1;
	heada = organise_arguments(argc, argv, &lena, &arrmoves);
	headb = NULL;
	index_list(&heada);
	if (is_in_order(&heada) == 1)
		return (0);
	work_out_which_func(lena, &arrmoves, &heada, &headb);
	end_program(&heada, &arrmoves);
}
