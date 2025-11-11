/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:13:04 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/11 11:13:06 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft_files/libft.h"

void	ft_percentage_id(va_list args, int *totalchars)
{
	int		num;
	char	*strtoprint;
	char	*start;

	num = va_arg(args, int);
	strtoprint = ft_itoa(num);
	start = strtoprint;
	if (!strtoprint)
		return ;
	while (*start)
	{
		*totalchars += 1;
		write(1, start, 1);
		start++;
	}
	free (strtoprint);
}

static void	ft_convert(unsigned int d, unsigned int n, char *s, int *totalchars)
{
	unsigned int	len;

	len = d;
	s[d] = '\0';
	while (d > 0)
	{
		d--;
		s[d] = (char)(n % 10) + '0';
		n = n / 10;
	}
	while (d < len)
	{
		write(1, &s[d], 1);
		d++;
		*totalchars += 1;
	}
}

void	ft_percentage_u(va_list args, int *totalchars)
{
	unsigned int	num;
	unsigned int	digits;
	unsigned int	copy;
	char			*str;

	digits = 1;
	num = va_arg(args, unsigned int);
	copy = num;
	if (num == 0)
	{
		write(1, "0", 1);
		*totalchars += 1;
		return ;
	}
	while (copy > 9)
	{
		digits++;
		copy = copy / 10;
	}
	str = malloc(digits + 1);
	if (!str)
		return ;
	ft_convert(digits, num, str, totalchars);
}
