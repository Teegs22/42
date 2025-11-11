/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:56:37 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/04 09:56:38 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_is_in(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		trimf;
	size_t		trime;
	size_t		len;
	char		*ptr;

	trimf = 0;
	trime = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[trimf] && check_is_in(s1[trimf], set))
		trimf++;
	while (s1[trimf] && check_is_in(s1[len - trime - 1], set))
		trime++;
	ptr = malloc((len - trimf - trime) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, (void *) s1 + trimf, len - trime - trimf);
	ptr[len - trimf - trime] = '\0';
	return (ptr);
}
