/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:52:54 by thelsdow          #+#    #+#             */
/*   Updated: 2026/02/06 12:52:56 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define SA 0
# define SB 1
# define PA 2
# define PB 3
# define RA 4
# define RB 5
# define RRA 6
# define RRB 7

# include <limits.h>
# include <stdlib.h>
# include "libft_files/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}	t_node;

t_node		*s_create_node(int *value, int **arrmoves);
void		end_program(t_node **heada, int **arrmoves);
void		free_list(t_node **heada);
int			check_is_int(char *str);
int			check_no_duplicates(char **str);
void		sort_which_move(int move, int **arrmoves,
				t_node **heada, t_node **headb);
void		add_move_to_list(int move, int **arrmoves);
int			check_for_errors(int argc, char **argv, int *i);
void		add_new_node_front(t_node **head, int *data, int **arrmoves);
void		build_array(int **a, int lena, char **argv, int argc);
void		index_list(t_node **heada);
void		ft_chunk_sort_to_b(int **a, t_node **heada,
				t_node **headb, int lena);
void		ft_chunk_sort_to_a(int **arrmoves, t_node **heada, t_node **headb);
void		sort_two_element_array(int **arrmoves, t_node **heada,
				t_node **headb);
void		sort_three_element_array(int **arrmoves, t_node **heada,
				t_node **headb);
void		sort_four_element_array(int **arrmoves, t_node **heada,
				t_node **headb, int onlyfour);
void		sort_five_element_array(int **arrmoves, t_node **heada,
				t_node **headb);
void		error(void);
void		ft_swap(t_node **head);
void		ft_push(t_node **pushfrom, t_node **pushto);
void		ft_rotate(t_node **head, int move);
int			compare_and_print(int *arrmoves, int i);
int			check_if_lowest_value(t_node *current, int found, int *lowest);
int			is_in_order(t_node **heada);
void		find_smallest_and_largest(t_node *heada,
				int *smallest, int *largest);
void		reverse_one_way(t_node **heada, int **arrmoves,
				t_node **headb, int smallest);
void		reassign_arrmoves(int **arrmoves, int **temp, int move);
t_node		*organise_arguments(int argc, char **argv, int *lena,
				int **arrmoves);
void		work_out_which_func(int lena, int **arrmoves, t_node **heada,
				t_node **headb);

#endif