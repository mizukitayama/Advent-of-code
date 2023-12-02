CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

SRCS	=	get_next_line.c get_next_line_utils.c

NAME	=	get_next_line.a

SRCS_OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	ar rcs $(NAME) $(SRCS_OBJS)

clean:
	$(RM) $(SRCS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)