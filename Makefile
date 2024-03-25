# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 12:52:59 by paulmart          #+#    #+#              #
#    Updated: 2024/03/25 15:11:50 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			main.c

OBJS				= $(SRC:.c=.o)
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= so_long

all:			$(NAME)

$(NAME):		$(OBJS)
						$(CC)-o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)
				$(RM) *~

fclean:			clean
				$(RM) $(NAME)

re:				fclean
	$(MAKE) $(NAME)

.PHONY: clean fclean re