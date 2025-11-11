/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:10:12 by thelsdow          #+#    #+#             */
/*   Updated: 2025/10/31 08:10:21 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//malloc(0) -undefined behaviour, malloc (1) returns unique pointer

void	*ft_calloc(size_t num_elements, size_t size)
{
	char	*ptr;
	size_t	total;

	total = num_elements * size;
	if (num_elements != 0 && (num_elements * size) / num_elements != size)
		return (NULL);
	if (total == 0)
		total = 1;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
