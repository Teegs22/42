/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:13:18 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/11 11:13:21 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft_files/libft.h"

void	ft_percentage_chars(va_list args, const char str, int *totalchars)
{
	char	num;

	if (str == '%')
	{
		*totalchars += 1;
		write(1, "%", 1);
	}
	if (str == 'c')
	{
		*totalchars += 1;
		num = (char)va_arg(args, int);
		write(1, &num, 1);
	}
}

void	ft_percentage_s(va_list args, int *totalchars)
{
	char	*strtoprint;

	strtoprint = va_arg(args, char *);
	if (!strtoprint)
		strtoprint = "(null)";
	while (*strtoprint)
	{
		write (1, strtoprint, 1);
		strtoprint ++;
		*totalchars += 1;
	}
}
