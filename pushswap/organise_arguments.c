/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:18:10 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/11 14:18:11 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*organise_arguments(int argc, char **argv, int *lena, int **arrmoves)
{
	int		i;
	int		*a;
	t_node	*heada;

	heada = NULL;
	// if (check_for_errors(argc, argv, lena) == 1)
	// 	error ();
	a = malloc(sizeof(int) * (*lena));
	if (!a || check_for_errors(argc, argv, lena) == 1)
	{
		free(arrmoves);
		free(a);
		error();
	}
	build_array(&a, (*lena), argv, argc);
	i = (*lena) - 1;
	while (i >= 0)
	{
		add_new_node_front(&heada, &a[i], arrmoves);
		i--;
	}
	free(a);
	return (heada);
}
