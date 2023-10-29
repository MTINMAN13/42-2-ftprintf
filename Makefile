
# Makefile for ft_printf


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE = include
LIBFT = libft

# Output file
NAME = libftprintf.a

# Sources
SRC_FILES = ft_hex_handler ft_int_handler ft_pointer_handler ft_print_handlers ft_printf
SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# Commands
RM = rm -f
AR = ar rcs

# Colors
COLOR_RESET = \033[0m
COLOR_RED = \033[0;91m
COLOR_GREEN = \033[0;92m
COLOR_BLUE = \033[0;94m
COLOR_CYAN = \033[0;96m

# Targets
.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(COLOR_GREEN)ft_printf compiled!$(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(COLOR_BLUE)Compiling: $<$(COLOR_RESET)"
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "$(COLOR_CYAN)ft_printf object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) -f $(NAME)
	@$(RM) -f libft.a
	@make fclean -C $(LIBFT)
	@echo "$(COLOR_CYAN)ft_printf and libft executable files cleaned!$(COLOR_RESET)"

re: fclean all
	@echo "$(COLOR_GREEN)Cleaned and rebuilt everything for ft_printf!$(COLOR_RESET)"

norm:
	@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true
