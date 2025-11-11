/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:17:27 by thelsdow          #+#    #+#             */
/*   Updated: 2025/10/30 16:17:30 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && len == 0)
		return (NULL);
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (i + j < len && to_find[j] && str[i + j] == to_find[j])
		{
			if (str[i + j])
				j++;
		}
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
