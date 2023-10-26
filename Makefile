


# added 24-10-- --   sample when exploring

NAME = printf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = src/printf.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ../path_to_libft_library
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I include -I $(LIBFT_DIR)/include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
