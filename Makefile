# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 12:52:59 by paulmart          #+#    #+#              #
#    Updated: 2024/06/14 13:06:36 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

src	=		main.c\
			put_image.c\
			map_init.c\
			movment.c\
			check_map.c\
			flood_fill.c\
			get_next_line.c\
			get_next_line_utils.c\

SRCS = $(addprefix ./srcs/, $(src))

OBJS = $(SRCS:.c=.o)


MLX_A = libmlx.a
MLX_DIR = ./lib/mlx/

PRINTF_A = libftprintf.a
PRINTF_DIR = ./lib/ft_printf/

FLAGS = lib/mlx/libmlx.a lib/mlx/libmlx_Linux.a -L. -lXext -L. -lX11
FT_PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

INCLUDE = includes/

.c.o :
	cc -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all: ${NAME}

$(PRINTF_A):
					make -C $(PRINTF_DIR)

$(MLX_A):		
					make -C $(MLX_DIR)


$(NAME): $(OBJS) $(PRINTF_A) $(MLX_A)
					cc ${OBJS} $(FLAGS) $(FT_PRINTF) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF_DIR)$(PRINTF_A)
	rm -f $(MLX_DIR)$(MLX_A)

re: fclean all

.PHONY: all clean fclean re