# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceia <jceia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 20:04:48 by jceia             #+#    #+#              #
#    Updated: 2021/08/30 20:04:49 by jceia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

SRCS_SRC	= server.c
SRCS_CLI	= client.c

OBJS_SRV	= $(SRCS_SRV:.c=.o)
OBJS_CLI	= $(SRCS_CLI:.c=.o)
OBJS		= $(OBJS_CLI) $(OBJS_SRV)

NAME		= minitalk
NAME_SRV	= server
NAME_CLI	= client

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $(<:.c=.o)

$(LIBFT):
			$(MAKE) -C $(LIBFTDIR)

$(NAME):	$(NAME_SRV) $(NAME_CLI)

$(NAME_SRV):$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLI):$(OBJS_CLI) $(LIBFT)
			$(CC) $(CFLAGS) $^ -o $@

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(NAME_CLI) $(NAME_SRV)

re:			fclean all

.PHONY:		all clean fclean re
