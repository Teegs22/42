
#defining the name of the static library
NAME = libftprintf.a

#compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft_files

#all of the source files
SRC = ft_printf.c ft_print_numbers.c ft_print_text.c ft_hex.c
LIBFT_SRC = $(wildcard libft_files/*.c)

#convert c files to object files (.c to .o) - doesnt build yet
OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

#Default command - buld the library

# Checks all the .o files in $(OBJ) exist to build $(NAME)/create library.
$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)
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
	rm -f $(OBJ) $(LIBFT_OBJ)

# Clean everything including the library
fclean: clean
	rm -f $(NAME)

#rebuilds it all.
re: fclean all

#UNIT TEST 
#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
#	gcc -nostartfiles -shared -o libft.so $(OBJ)

#test: $(NAME) main.o
#	$(CC) $(CFLAGS) main.o -L. -lftprintf -o test

#main.o: main.c
#	$(CC) $(CFLAGS) -c main.c -o main.o

.PHONY: all clean fclean re
