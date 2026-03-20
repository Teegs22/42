/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_up_the_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:02:27 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/06 13:02:29 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_no_duplicates(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != NULL)
	{
		if (str[i + j] == NULL)
		{
			j = 1;
			i++;
		}
		else
		{
			if (ft_strncmp(str[i], str[i + j], 12) == 0)
				return (0);
			j++;
		}
	}
	return (1);
}

static int	split_up_string_to_int(int *i, int fail, char **argv)
{
	char	**numbers;

	numbers = ft_split(argv[1], ' ');
	if (!numbers || check_no_duplicates(numbers) == 0)
		return (1);
	while (numbers[(*i)])
	{
		if (!check_is_int(numbers[(*i)]))
			fail = 1;
		(*i)++;
	}
	(*i) = 0;
	while (numbers[(*i)])
	{
		free(numbers[(*i)]);
		(*i)++;
	}
	free(numbers);
	return (fail);
}

int	check_for_errors(int argc, char **argv, int *i)
{
	int			fail;

	fail = 0;
	if (argc == 2 && check_is_int(argv[1]) == 1)
		exit(0);
	else if (argc > 2)
	{
		while ((*i) + 1 < argc && check_is_int(argv[(*i) + 1]))
			(*i)++;
		if (check_is_int(argv[(*i)]) == 0 || check_no_duplicates(argv + 1) == 0)
			return (1);
	}
	else if (argc == 2)
		fail = split_up_string_to_int(i, fail, argv);
	return (fail);
}

void	build_array(int **a, int lena, char **argv, int argc)
{
	int		i;
	char	**numbers;

	i = 0;
	if (lena == argc - 1)
	{
		while (i < lena)
		{
			(*a)[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	else
	{
		numbers = ft_split(argv[1], ' ');
		while (numbers[i])
		{
			(*a)[i] = ft_atoi(numbers[i]);
			i++;
		}
	}
}

int	is_in_order(t_node **heada)
{
	t_node	*current;

	current = (*heada)->next;
	while (current->prev->data < current->data && current != (*heada))
		current = current->next;
	if (current == (*heada))
		return (1);
	return (0);
}
