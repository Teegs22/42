/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:10:36 by thelsdow          #+#    #+#             */
/*   Updated: 2025/10/30 09:10:37 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned const char	*ptrsrc;
	unsigned char		*ptrdest;
	size_t				i;

	if (dest == src || len == 0)
		return (dest);
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned const char *)src;
	i = 0;
	while (i < len)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
