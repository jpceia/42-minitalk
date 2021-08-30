# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceia <jceia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 20:04:48 by jceia             #+#    #+#              #
#    Updated: 2021/08/30 21:27:49 by jceia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

DEPS		= .

SRCS_SRV	= minitalk.c server.c
SRCS_CLI	= minitalk.c client.c

OBJS_SRV	= $(SRCS_SRV:.c=.o)
OBJS_CLI	= $(SRCS_CLI:.c=.o)
OBJS		= $(OBJS_CLI) $(OBJS_SRV)

NAME		= minitalk
NAME_SRV	= server
NAME_CLI	= client

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I$(DEPS) -g

all:		$(NAME_SRV) $(NAME_CLI)

.c.o:
			$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $(<:.c=.o)

$(LIBFT):
			$(MAKE) -C $(LIBFTDIR)

$(NAME_SRV):$(OBJS_SRV) $(LIBFT)
			$(CC) $(CFLAGS) $^ -o $(NAME_SRV)

$(NAME_CLI):$(OBJS_CLI) $(LIBFT)
			$(CC) $(CFLAGS) $^ -o $(NAME_CLI)

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(NAME_CLI) $(NAME_SRV)

re:			fclean all

.PHONY:		all clean fclean re
