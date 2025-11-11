/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:55:56 by thelsdow          #+#    #+#             */
/*   Updated: 2025/10/30 09:55:57 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if dest = src (point to exact same mem loc) returns dest w no change.
//if dest > src (the mem location pointed to > src) copies forwards 
//if dest < src = copies backwards from btc -1 = the index not length

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t btc)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == src || btc == 0)
		return (dest);
	if (dest > src)
	{
		while (btc > 0)
		{
			btc--;
			d[btc] = s[btc];
		}
	}
	else
	{
		while (btc--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
