
#defining the name of the static library

LIBFT_DIR  = libft_files

NAME = push_swap
LIBFT = $(LIBFT_DIR)/libft.a

#compiler and flags -I finds header files in pushswap so pushswap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I./$(LIBFT_DIR)

#all of the source files
SRC = \
		push_swap.c \
		sort_small_elements.c \
		instructions.c \
		s_create_node.c \
		clean_up_files.c \
		setting_up_the_array.c \
		indexing_array.c \
		chunk_sort_algorithm.c \
		helper_functions.c \
		organise_arguments.c

#convert c files to object files (.c to .o) - doesnt build yet
OBJ = $(SRC:.c=.o)

#Default command - buld the library libftprintf.a by running make
all: $(NAME)

# Checks all the .o files in $(OBJ) exist to build $(NAME)/create library.
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

#this line above actually runs to build library.
#ar (archiver) used to create static libraries (.a)
#r replaces file in archive/adds if not there. c creates archive if it doesnt exist yet.
#s tells ar to write an index (symbol table)- linker can quickly locate symbols.

$(LIBFT): 
	make -C ./libft_files

# Compile .c files to .o files - teaches how to build a .o file from a .c file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#so if any are missing it does gcc -Wall -Werror -Wextra filename.c -o filename.o

# Clean object files
clean:
	rm -f $(OBJ)
	make -C libft_files clean

# Clean everything including the library
fclean: clean
	rm -f $(NAME)
	make -C libft_files fclean

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
