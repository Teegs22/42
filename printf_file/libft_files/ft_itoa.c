/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 07:57:15 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/05 07:57:16 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(int negative, int digits, int n, char *str)
{
	int		i;

	i = 0;
	if (negative == 1)
	{
		str[0] = '-';
		n = -n;
	}
	str[digits + negative] = '\0';
	i = digits + negative - 1;
	while (digits > 0)
	{
		str[i] = (char)(n % 10) + '0';
		n = n / 10;
		digits --;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		copy;
	int		digits;
	int		negative;
	char	*str;

	digits = 1;
	copy = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		negative = 1;
		copy = -copy;
	}
	else
		negative = 0;
	while (copy > 9)
	{
		digits++;
		copy = copy / 10;
	}
	str = malloc(negative + digits + 1);
	if (!str)
		return (NULL);
	return (ft_convert(negative, digits, n, str));
}
