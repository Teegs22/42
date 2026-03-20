/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:35:59 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/04 15:36:01 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fail_allocation(int n, char **arr)
{
	while (n >= 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr);
	return (NULL);
}

static int	length_of_array(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i])
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] && s[i] != c)
			{
				count++;
				while (s[i] && s[i] != c)
					i++;
			}
		}
	}
	return (count);
}

static char	**set_array(char **arr, char c, char const *s, int n)
{
	unsigned int	len;

	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			arr[n] = malloc(len + 1);
			if (!arr[n])
				fail_allocation(n - 1, arr);
			ft_strlcpy(arr[n], (char *)s - len, len + 1);
			n++;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**arr;

	if (!s)
		return (NULL);
	num_words = length_of_array(s, c);
	arr = malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (NULL);
	arr[num_words] = NULL;
	arr = set_array(arr, c, s, 0);
	if (!arr)
		return (NULL);
	return (arr);
}
