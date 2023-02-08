# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 14:10:25 by synicole          #+#    #+#              #
#    Updated: 2022/11/29 14:10:27 by synicole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 			= fdf
CC				= gcc -g
FLAGS 			= -Wall -Werror -Wextra
SANITIZE		= -fsanitize=address
FRAMEWORK		= -framework OpenGL -framework AppKit

# OBJ
FDF_OBJ			= $(FDF_SRC:.c=.o)

# SOURCES
FDF_SRC			= ./srcs/fdf.c \
				  ./srcs/print.c

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
all:			$(NAME)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

$(NAME): 		$(FDF_OBJ)
				make -C ft_printf
				make -C mlx
				$(CC) $(FLAGS) $(FDF_OBJ) ft_printf/ft_printf.a ft_printf/libft/libft.a -Lmlx -lmlx $(FRAMEWORK) -o $(NAME)
				@echo "$(_SUCCESS)🚀Build FDF!$(_END)"

%.o: %.c
				$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
				make clean -C ft_printf
				make clean -C mlx
				/bin/rm -rf $(FDF_OBJ)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				make fclean -C ft_printf
				/bin/rm -rf $(NAME)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

.PHONY:			all clean fclean re