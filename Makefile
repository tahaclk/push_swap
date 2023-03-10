CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
NAME			= push_swap
NAME_CHCK		= checker

SRC_PS_PATH		= src/push_swap/
OBJ_PS_PATH		= obj/push_swap/

SRC_CHCK_PATH	= src/checker/
OBJ_CHCK_PATH	= obj/checker/


SRC			= main.c ft_split.c\
			input_check.c input_check_utils.c \
			initialization.c \
			stack.c \
			swap.c push.c rotate.c reverse_rotate.c \
			sort_tiny.c sort.c \
			position.c cost.c do_move.c \
			utils.c

SRC_CHCK	= main.c ft_split.c \
			input_check.c input_check_utils.c \
			initialization.c \
			stack.c get_next_line.c \
			get_next_line_utils.c swap.c push.c \
			rotate.c reverse_rotate.c position.c \
			utils.c
SRCS			= $(addprefix $(SRC_PS_PATH), $(SRC))
OBJ				= $(SRC:.c=.o)
OBJS			= $(addprefix $(OBJ_PS_PATH), $(OBJ))

SRCS_C			= $(addprefix $(SRC_CHCK_PATH), $(SRC_CHCK))
OBJ_C			= $(SRC_CHCK:.c=.o)
OBJS_C			= $(addprefix $(OBJ_CHCK_PATH), $(OBJ_C))

all:	$(OBJ_PS_PATH) $(NAME)

bonus:	$(OBJ_CHCK_PATH) $(NAME_CHCK)

$(OBJ_PS_PATH)%.o: $(SRC_PS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CHCK_PATH)%.o: $(SRC_CHCK_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PS_PATH):
	mkdir $(OBJ_PS_PATH)

$(OBJ_CHCK_PATH):
	mkdir $(OBJ_CHCK_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_CHCK): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_CHCK)

clean:
	rm -rf $(OBJ_PS_PATH) $(OBJ_CHCK_PATH)

fclean: clean
	rm -f $(NAME) $(NAME_CHCK)

re: fclean all

.PHONY: all clean fclean re bonus
