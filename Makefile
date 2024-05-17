# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 12:52:59 by paulmart          #+#    #+#              #
#    Updated: 2024/05/17 15:39:07 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c put_image.c map_init.c
SRC_GNL	=	= get_next_line.c get_next_line_utils.c

SRCS		= $(addprefix ./srcs/, $(SRC))
SRCS_GNL	= $(addprefix ./lib/, $(SRC_GNL))

OBJS			= $(SRCS:.c=.o)
OBJS_GNL		= $(SRCS_GNL:.c=.o)

CC				= cc
CFLAGS			= lib/mlx/libmlx_Linux.a lib/mlx/libmlx.a -lX11 -lXext
NAME			= so_long
PRINTF_DIR		= lib/ft_printf
FT_PRINTF		= lib/ft_printf/libftprintf.a
all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C $(PRINTF_DIR)
				$(CC) $(OBJS) $(CFLAGS) $(FT_PRINTF) -o $(NAME)

clean:
				$(RM) $(OBJS) $(OBJS_GNL)
				$(RM) *~
				$(MAKE) clean -C $(PRINTF_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(MAKE) fclean -C $(PRINTF_DIR)

re:				fclean
				$(MAKE) $(NAME)

.PHONY: clean fclean re