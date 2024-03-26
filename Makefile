# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 12:52:59 by paulmart          #+#    #+#              #
#    Updated: 2024/03/26 16:51:18 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c put_image.c

SRCS		= $(addprefix ./srcs/, $(SRC))

OBJS			= $(SRCS:.c=.o)
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
				$(RM) $(OBJS)
				$(RM) *~
				$(MAKE) clean -C $(PRINTF_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(MAKE) fclean -C $(PRINTF_DIR)

re:				fclean
				$(MAKE) $(NAME)

.PHONY: clean fclean re