/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:11:40 by thelsdow          #+#    #+#             */
/*   Updated: 2025/10/14 12:11:42 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char			*ptr;
	unsigned char	uc;

	uc = (unsigned char)c;
	ptr = s;
	while (*s)
		s++;
	while (s >= ptr)
	{
		if ((unsigned char)*s == uc)
			return (s);
		s--;
	}
	return (NULL);
}
