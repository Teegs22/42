/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:28:29 by thelsdow          #+#    #+#             */
/*   Updated: 2025/10/30 11:28:31 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	len;

	destlen = 0;
	srclen = 0;
	while (destlen < size && dest[destlen])
		destlen++;
	while (src[srclen])
		srclen++;
	len = srclen + destlen;
	if (size <= destlen)
		return (size + srclen);
	srclen = 0;
	while (src[srclen] && destlen < size - 1)
	{
		dest[destlen] = src[srclen];
		destlen++;
		srclen++;
	}
	dest[destlen] = '\0';
	return ((unsigned int)len);
}
