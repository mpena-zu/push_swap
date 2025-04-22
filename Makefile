NAME = push_swap

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

BONUS_DIR = bonus

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SOURCES = push_swap.c moves_a.c moves_b.c moves_both.c rules.c is_not_sorted.c \
			cost.c init_nodes.c main.c moves_big.c sort_stacks.c utils_stack.c

BONUS_SOURCES = $(BONUS_DIR)/checker_utils.c \
			$(BONUS_DIR)/push_swap_bonus.c \
			$(BONUS_DIR)/rules_bonus.c \
			$(BONUS_DIR)/utils_stack_bonus.c \
			$(BONUS_DIR)/moves_a_bonus.c \
			$(BONUS_DIR)/moves_b_bonus.c \
			$(BONUS_DIR)/moves_both_bonus.c \
			$(BONUS_DIR)/get_next_line.c \
			$(BONUS_DIR)/main_checker.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

GREEN = \033[0;32m
NC = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m
TOTAL_OBJ = $(words $(OBJECTS))

TOTAL_BONUS_OBJ = $(words $(BONUS_OBJECTS))

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) --no-print-directory

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@$(MAKE) -s progress
	@echo ""
	@echo "$(GREEN)¡Compilación push_swap completada!$(NC)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(FT_PRINTF) -o $(BONUS_NAME)
	@$(MAKE) -s progress TOTAL_OBJ=$(TOTAL_BONUS_OBJ) OBJECTS="$(BONUS_OBJECTS)"
	@echo ""
	@echo "$(GREEN)¡Compilación del checker completada!$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(MAKE) -s progress

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(BONUS_DIR) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@make -C $(FT_PRINTF_DIR) clean --no-print-directory
	@$(RM) $(OBJECTS)
	@echo "$(YELLOW)¡Dejamos todo preparado para el push_swap!$(NC)"

clean_bonus:
	@$(RM) $(BONUS_OBJECTS)
	@echo "$(YELLOW)¡Dejamos todo preparado para el checker!$(NC)"

fclean:
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@make -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@$(RM) $(OBJECTS) $(NAME)
	@echo "$(RED)¡Todo limpio del push_swap!$(NC)"

fclean_bonus:
	@$(RM) $(BONUS_OBJECTS) $(BONUS_NAME)
	@echo "$(RED)¡Todo limpio del checker!$(NC)"

re: fclean all

re_bonus: fclean_bonus bonus

progress:
	@$(eval COMPLETED = $(shell ls -1 $(OBJECTS) 2>/dev/null | wc -l))
	@$(eval PERCENTAGE = $(shell echo "scale=2; 100 * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval BAR_LENGTH = 50)
	@$(eval FILLED_LENGTH = $(shell echo "$(BAR_LENGTH) * $(COMPLETED) / $(TOTAL_OBJ)" | bc))
	@$(eval EMPTY_LENGTH = $(shell echo "$(BAR_LENGTH) - $(FILLED_LENGTH)" | bc))
	@echo -n "$(GREEN)["
	@$(eval BAR = $(shell yes "=" | head -n $(FILLED_LENGTH) | tr -d '\n'))
	@$(eval EMPTY = $(shell yes " " | head -n $(EMPTY_LENGTH) | tr -d '\n'))
	@echo -n "$(BAR)$(EMPTY)"
	@echo -n "] $(PERCENTAGE)%"
	@echo -n "\r"
	@sleep 0.05

.PHONY: all clean fclean re progress bonus clean_bonus fclean_bonus re_bonus