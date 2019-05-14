# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 08:57:37 by tpompon           #+#    #+#              #
#    Updated: 2019/05/13 15:31:33 by tpompon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
NAME = fractol

# Paths
INC_PATH = ./inc/
SRC_PATH = ./src/
LFT_PATH = ./libft/

# MLX
MLX = -lmlx -framework OpenGL -framework AppKit

# Color codes
NC=\x1b[0m
WHITEBG=\x1b[7;39;01m
REDBG=\x1b[7;31;01m
BLUE=\x1b[34;01m
GREEN=\x1b[32;01m
YELLOW=\x1b[33;01m

# Sources and Objects files
SRC =	src/main.c \
		src/event.c \
		src/display.c \
		src/mandelbrot.c \
		src/julia.c \
		src/burning_ship.c \
		src/tricorn.c \
		src/clover.c \
		src/utils.c

OBJ = $(SRCS:.c=.o)

# Rules
all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $^

$(NAME): $(SRC)
	@echo tpompon > auteur
	@make -C ./libft all
	$(CC) $(FLAGS) -I$(INC_PATH) -L$(LFT_PATH) -lft $(MLX) -o $(NAME) $(SRC)
	@echo "\n$(REDBG)[Fract'ol]$(NC) \t$(BLUE) You can execute $(YELLOW)./$(NAME)$(NC) \t$(GREEN)[√]$(NC)\n"
	@echo "$(WHITEBG)Renders available:$(NC) \t[Mandelbrot] [Julia] [Burning_Ship] [Tricorn] [Clover]\n"

clean:
	@rm -f $(OBJS)
	@make -C $(LFT_PATH) clean
	@echo "\n$(REDBG)[Fract'ol]$(NC) \t$(BLUE)Objects files removed$(NC) \t$(GREEN)[√]$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LFT_PATH) fclean
	@echo "\n$(REDBG)[Fract'ol]$(NC) \t$(BLUE)Executable removed$(NC) \t$(GREEN)[√]$(NC)\n"

norme:
	@echo "\n$(BLUE)Norminette - Sources files$(NC)\n"
	@norminette $(SRC_PATH)*.c
	@echo "\n$(BLUE)Norminette - Includes files$(NC)\n"
	@norminette $(INC_PATH)

re: fclean all
