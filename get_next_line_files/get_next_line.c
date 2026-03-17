/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:24:36 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/17 16:24:38 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_adjust_str(char *str, int len)
{
	int	i;

	i = 0;
	while (len <= BUFFER_SIZE && str[len])
	{
		str[i] = str[len];
		i++;
		len++;
	}
	str[i] = '\0';
}

static char	*ft_assign_arr(char *arr, int len, char *str, int i)
{
	char	*temp;

	if (!arr)
	{
		arr = malloc(len + 1);
		if (!arr)
			return (NULL);
		while (++i < len)
			arr[i] = str[i];
		arr[i] = '\0';
	}
	else
	{
		temp = malloc(len + 1);
		if (!temp)
			return (NULL);
		while (++i < len)
			temp[i] = str[i];
		temp[i] = '\0';
		arr = ft_strjoin(arr, temp);
		free(temp);
		if (!arr)
			return (NULL);
	}
	return (arr);
}

static char	*ft_loop_through_str(char *str, char *arr)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
	{
		arr = ft_assign_arr(arr, len + 1, str, -1);
		if (!arr)
			return (NULL);
		ft_adjust_str(str, len + 1);
		return (arr);
	}
	else
	{
		arr = ft_assign_arr(arr, len, str, -1);
		if (!arr)
			return (NULL);
		ft_memset(str, '\0', BUFFER_SIZE + 1);
	}
	return (arr);
}

char	*get_next_line(int fd)
{
	static char		str[BUFFER_SIZE + 1];
	char			*arr;
	int				len;

	arr = NULL;
	while (1)
	{
		if (str[0])
		{
			if (ft_strchr(str, '\n') != NULL)
				return (ft_loop_through_str(str, arr));
			arr = ft_loop_through_str(str, arr);
			if (!arr)
				return (NULL);
		}
		len = read(fd, str, BUFFER_SIZE);
		if (len <= 0)
			break ;
		str[len] = '\0';
	}
	return (arr);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main (int argc, char **argv)
// {
// 	int	fd;
// 	char	*line;

// 	(void)argc;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("answer: %s", line);
// 		free(line);
// 	}
// 	// close(fd);
// 	// free(line);
// 	return (close(fd), 0);
// }
