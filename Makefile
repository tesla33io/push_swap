# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 17:41:15 by astavrop          #+#    #+#              #
#    Updated: 2024/02/17 20:54:33 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -g
DEBUGFLAGS			:= -g
LIBS				= -Lft_printf/ -lftprintf -Llibft/ -lft
INCLUDES			= -I./ft_printf/includes -I./libft/ -I.
NAME				:= push_swap


SRCS				+= 1_main.c
SRCS				+= 2_process_input.c
OBJ_DIR				:= ./obj/
OBJS				:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))


DEPS				:= $(OBJS:.o=.d)


FT_PRINTF_PATH		= ./ft_printf/
FT_PRINTF_BIN		= $(FT_PRINTF_PATH)libftprintf.a


LFT_PATH			= ./libft/
LFT_BIN				= $(LFT_PATH)libft.a


all: $(NAME)

.DEFAULT_GOAL := all


-include $(DEPS)


$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o,%.d,$@) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS) $(LFT_BIN) $(FT_PRINTF_BIN)
	@echo -n "\033[32;49;3m... Compiling code ...\033[0m\r"
	@$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS)
	@echo "\033[32;49;1m>>>   Done!   <<<\033[0m          "


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

re: fclean all


.PHONY: all clean fclean re