/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:05:59 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/05 09:06:04 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	len = 0;
	while (s[len])
	{
		ptr[len] = f(len, s[len]);
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
