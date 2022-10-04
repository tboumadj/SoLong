# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 09:05:08 by tboumadj          #+#    #+#              #
#    Updated: 2022/09/27 15:36:33 by tboumadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =   so_long
SRCS =  srcs/main.c \
	srcs/fonc_maps.c \
	srcs/action_player.c \
	srcs/check_rules.c \
	srcs/fonc_utils.c \
	srcs/check_maps.c \
	srcs/algo_road.c \
	srcs/game.c \
	srcs/sprites.c \
	srcs/init_sprites.c \
	srcs/fonc_player.c \
	srcs/fonc_free.c \
	srcs/fonc_plus.c
CC =   gcc
FLAGS =   -Wall -Wextra -Werror -g
MLX	= -Lmlx -lmlx -framework OpenGl -framework AppKit
RM =   rm -f
CHECK = -fsanitize=address
HEADER = srcs/so_long.h
OBJS = $(SRCS:.c=.o)

# Couleurs
_RED    =   $'\x1b[31m
_GREEN  =   $'\x1b[32m

.c.o:
	@$(CC) $(FLAGS) -Imlx -c $< -o $(<:c=o)

$(NAME): $(OBJS)
	@echo "$(_RED)Compilation libft.a en cours...$(_END)"
	@$(MAKE) -C libft/
	@$(MAKE) -C mlx/
	@$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) $(MLX)
	@echo "$(_RED)Compilation so_long en cours...$(_END)"
	@echo "$(_GREEN)$(_BOLD)Fin de la compilation!$(_END)"

.SILENT : $(NAME) $(OBJS) 

all     :   $(NAME)

clean   :
			$(MAKE) clean -C libft/
			$(RM) $(OBJS)
fclean  :	clean
			$(MAKE) fclean -C libft/ 
			$(MAKE) clean -C mlx/
			$(RM) libmlx.a $(NAME)
re      :   fclean all
.PHONY  :   all clean fclean re
