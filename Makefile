# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:16:21 by arasal            #+#    #+#              #
#    Updated: 2023/04/20 16:17:47 by arasal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Variables
NAME	= Fractol
B_NAME	= Fractol_bonus
CC 		= gcc
CFLAGS	= -Werror -Wall -Wextra
LIBMLX	= ./MLX42
LIBFT	= ./Libft

# File Variables
HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -lglfw -L ~/goinfre/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= fractol.c mandelbrot.c julia.c math.c get_next_line_bonus.c get_next_line_utils_bonus.c\
		  hooks.c utils.c parameters.c newton_bonus.c
OBJS	= ${SRCS:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: libft libmlx $(NAME)

libft:
	@$(MAKE) --silent -C $(LIBFT)

libmlx:
	@$(MAKE) --silent -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(MAGENTA)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(MAKE) --silent -C $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(BOLD)\033[32mFractol is Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

bonus: $(OBJS)
	@$(MAKE) --silent -C $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(BOLD)\033[32mFractol is Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"


clean:
	@rm -f $(OBJS)
	@$(MAKE) --silent -C $(LIBFT) clean
	@$(MAKE) --silent -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --silent -C $(LIBFT) fclean
	@$(MAKE) --silent -C $(LIBMLX) fclean
	@echo "$(BOLD)\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
