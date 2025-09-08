
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = push_swap

SRC_DIR = src
OBJ_DIR = objects

VPATH = $(SRC_DIR)/moves:$(SRC_DIR)/ps_utils:$(SRC_DIR)/sorters:$(SRC_DIR)

SRCS = 	push_swap.c \
		sa.c sb.c ss.c \
		pb.c pa.c \
		ra.c rb.c rr.c \
		rra.c rrb.c rrr.c \
		ft_assign_index.c ft_atoi.c ft_check_ordered.c ft_simple_sort.c \
		lists.c nodes.c \
		mini_ksort.c ksort.c

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
