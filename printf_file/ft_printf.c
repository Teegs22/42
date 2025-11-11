/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 07:36:29 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/11 07:36:30 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft_files/libft.h"

static void	sort_out_percent(va_list args, const char str, int *totalchars)
{
	if (ft_strchr("id", str) != NULL)
		ft_percentage_id(args, totalchars);
	else if (ft_strchr("xX", str) != NULL)
		ft_percentage_x(args, str, totalchars);
	else if (ft_strchr("c%", str) != NULL)
		ft_percentage_chars(args, str, totalchars);
	else if (ft_strchr("u", str) != NULL)
		ft_percentage_u(args, totalchars);
	else if (ft_strchr("p", str) != NULL)
		ft_percentage_p(args, totalchars);
	else if (ft_strchr("s", str) != NULL)
		ft_percentage_s(args, totalchars);
}

int	ft_printf(const char *str, ...)
{
	int		totalchars;
	va_list	args;

	totalchars = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str != '%')
		{
			write(1, str, 1);
			str++;
			totalchars++;
		}
		if (*str && *str == '%')
			sort_out_percent(args, *(str + 1), &totalchars);
		if (*str == '\0')
			return (totalchars);
		str += 2;
	}
	va_end(args);
	return (totalchars);
}
