/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 08:04:12 by thelsdow          #+#    #+#             */
/*   Updated: 2025/11/05 08:04:15 by thelsdow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H  // check if LIBFT_H isnt defined
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *ptr, size_t len);
void			*ft_calloc(size_t num_elements, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int str);
int				ft_isascii(int num);
int				ft_isdigit(int num);
int				ft_isprint(int num);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(void *ptr1, void *ptr2, size_t num);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t btc);
void			*ft_memset(void *ptr, int c, size_t len);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(const char *s);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(char *s, int c);
int				ft_tolower(int a);
int				ft_toupper(int a);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
