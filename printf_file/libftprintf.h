/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:24:34 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/11 11:24:40 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H  // check if it isnt defined
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft_files/libft.h"

int		ft_printf(const char *str, ...);
void	ft_percentage_x(va_list args, const char str, int *totalchars);
void	ft_percentage_p(va_list args, int *totalchars);
void	ft_percentage_chars(va_list args, const char str, int *totalchars);
void	ft_percentage_s(va_list args, int *totalchars);
void	ft_percentage_id(va_list args, int *totalchars);
void	ft_percentage_u(va_list args, int *totalchars);

#endif
