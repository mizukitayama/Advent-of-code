CC              = gcc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -rf
AR              = ar rcs

SRCS            = trebuchet.c
GET_NEXT_LINE   = get_next_line/
GET_NEXT_LINE_NAME = get_next_line.a
NAME            = trebuchet.a
EXEC_NAME       = trebuchet

LIB_DIR         = lib/
OBJ_DIR         = obj/
SRC_DIR         = src/

SRCS_OBJS       = $(SRCS:.c=.o)
OBJS            = $(addprefix $(OBJ_DIR), $(SRCS_OBJS))

INCLUDE         = -I $(GET_NEXT_LINE)

all: $(NAME) $(EXEC_NAME)

$(NAME): $(OBJS)
	make -C $(GET_NEXT_LINE)
	cp $(GET_NEXT_LINE)$(GET_NEXT_LINE_NAME) $(LIB_DIR)
	mkdir -p $(LIB_DIR)
	$(AR) $(LIB_DIR)$(NAME) $(OBJS)

$(EXEC_NAME): $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(EXEC_NAME) $(SRC_DIR)$(SRCS) $(LIB_DIR)$(NAME) $(LIB_DIR)$(GET_NEXT_LINE_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

clean:
	make clean -C $(GET_NEXT_LINE)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(GET_NEXT_LINE)
	$(RM) $(LIB_DIR)$(NAME)
	$(RM) $(EXEC_NAME)
	$(RM) $(LIB_DIR)$(GET_NEXT_LINE_NAME)

re: fclean all
	make re -C $(GET_NEXT_LINE)
