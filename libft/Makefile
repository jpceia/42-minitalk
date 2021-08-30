NAME		= libft.a

SRCDIR		= src
OBJDIR		= obj
INCDIR		= .

# SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
SRCS		= $(wildcard $(SRCDIR)/*.c)
OBJS		= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR)

all:		$(NAME)

test:
		echo $(SRCS)

$(OBJS)	:	$(OBJDIR)/%.o : $(SRCDIR)/%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiled "$<" successfully"

$(NAME):	$(OBJS)
			@ar rc $@ $(OBJS)
			@echo "Created "$@

clean:
			$(RM) -r $(OBJDIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
