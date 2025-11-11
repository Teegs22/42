# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelsdow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 11:08:00 by thelsdow          #+#    #+#              #
#    Updated: 2025/10/31 11:08:09 by thelsdow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#defining the name of the static library
NAME = libft.a

#compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#all of the source files
SRC = ft_atoi.c ft_bzero.c ft_isalpha.c ft_isalnum.c ft_calloc.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

#convert c files to object files (.c to .o) - doesnt build yet
OBJ = $(SRC:.c=.o)

#Default command - buld the library

# Checks all the .o files in $(OBJ) exist to build $(NAME)/create library.
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
#this line above actually runs to build library.
#ar (archiver) used to create static libraries (.a)
#r replaces file in archive/adds if not there. c creates archive if it doesnt exist yet.
#s tells ar to write an index (symbol table)- linker can quickly locate symbols.

# Compile .c files to .o files - teaches how to build a .o file from a .c file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#so if any are missing it does gcc -Wall -Werror -Wextra filename.c -o filename.o

all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything including the library
fclean: clean
	rm -f $(NAME)

#rebuilds it all.
re: fclean all

#UNIT TEST 
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
#	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re
