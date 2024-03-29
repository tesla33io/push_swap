# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 17:41:15 by astavrop          #+#    #+#              #
#    Updated: 2024/03/12 20:55:01 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -g
DEBUGFLAGS			:= -g
LIBS				:= -Lft_printf/ -lftprintf -Llibft/ -lft
INCLUDES			:= -I./include/ -I./ft_printf/includes -I./libft/ -I.
NAME				:= push_swap


CFILES				+= main.c						# Main
CFILES				+= validation/parse.c			# Validation
CFILES				+= validation/check_input.c		# #
CFILES				+= algo/sort.c					# Sorting / Algo
CFILES				+= algo/sort_three.c			# #
CFILES				+= algo/helpers.c				# #
CFILES				+= algo/sort_utils_ab.c			# #
CFILES				+= algo/sort_utils_ba.c			# #
CFILES				+= algo/sort_calc_rotations.c	# #
CFILES				+= algo/move_utils.c			# #
CFILES				+= ops/do_push.c				# Operations
CFILES				+= ops/do_rotate.c				# #
CFILES				+= ops/do_swap.c				# #
CFILES				+= utils/deque_utils.c			# Utils
CFILES				+= utils/ft_abs.c				# #
CFILES				+= utils/avg.c					# #
CFILES				+= utils/minmax.c				# #
CFILES				+= clear/clear.c				# Clear


OBJ_DIR				:= ./obj/
OBJS				:= $(patsubst %.c, $(OBJ_DIR)%.o, $(CFILES))


DEPS				:= $(OBJS:.o=.d)


FT_PRINTF_PATH		= ./ft_printf/
FT_PRINTF_BIN		= $(FT_PRINTF_PATH)libftprintf.a


LFT_PATH			= ./libft/
LFT_BIN				= $(LFT_PATH)libft.a


all: $(NAME)

.DEFAULT_GOAL := all


-include $(DEPS)


$(OBJ_DIR)%.o: */%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o,%.d,$@) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS) $(LFT_BIN) $(FT_PRINTF_BIN)
	@echo -n "\033[32;49;3m... Compiling code ...\033[0m\r"
	@$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS)
	@echo "\033[32;49;1m>>>   Done!   <<<\033[0m          "


test: $(NAME)
	@echo "\033[32;49;3m\tRun simple test\033[0m"
	@-./$(NAME) 2 1 3 6 5 8


$(FT_PRINTF_BIN):
	@echo -n "\033[32;49;3m... Making ft_printf ...\033[0m\r"
	@$(MAKE) -sC $(FT_PRINTF_PATH)
	@echo "\033[32;49;1m> ft_printf ready! <        \033[0m"


$(LFT_BIN):
	@echo -n "\033[32;49;3m... Making libft ...\033[0m\r"
	@$(MAKE) -sC $(LFT_PATH)
	@echo "\033[32;49;1m> libft ready! <            \033[0m"


clean:
	@$(MAKE) -sC $(FT_PRINTF_PATH) clean
	@$(MAKE) -sC $(LFT_PATH) clean
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "\033[32;1mObjects cleand!\033[0m"

fclean: clean
	@$(MAKE) -sC $(FT_PRINTF_PATH) fclean
	@$(MAKE) -sC $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "\033[32;1mEverything cleand!\033[0m"

# TODO: remove before submitting
norm: $(addprefix src/, $(CFILES))
	norminette $(addprefix src/, $(CFILES)) include/*


re: fclean all test


.PHONY: all clean fclean re
