INCDIR		= .

LIBFTDIR	= ./libft
LIBFT		= libft/libft.a

SRCS		= server.c
SRCS_CLI	= client.c

OBJS		= $(SRCS:.c=.o)
OBJS_CLI	= $(SRCS_CLI:.c=.o)

NAME		= server

MAKE		= make
CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -I$(LIBFTDIR) -c $< -o ${<:.c=.o}

$(LIBFT):
			$(MAKE) bonus -C $(LIBFTDIR)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) ${CFLAGS} $(OBJS) $(LIBFT) -o $(NAME)

client:		$(OBJS_CLI) $(LIBFT)
			$(CC) ${CFLAGS} $(OBJS_CLI) $(LIBFT) -o client

clean:
			$(MAKE) -C $(LIBFTDIR) clean
			$(RM) $(OBJS) $(OBJS_CHECKER)

fclean:
			$(MAKE) -C $(LIBFTDIR) fclean
			$(RM) $(OBJS)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
