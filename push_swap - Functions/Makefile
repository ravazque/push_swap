# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 19:25:28 by ravazque          #+#    #+#              #
#    Updated: 2024/12/11 19:03:50 by ravazque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = push_swap

VPATH = moves:ps_utils:sorters:

OBJ_DIR = objects

SRCS = 	push_swap.c \
		sa.c \
		sb.c \
		ss.c \
		pb.c \
		pa.c \
		ra.c \
		rb.c \
		rr.c \
		rra.c \
		rrb.c \
		rrr.c \
		ft_assign_index.c \
		ft_atoi.c \
		ft_check_ordered.c \
		ft_simple_sort.c \
		lists.c \
		nodes.c \
		mini_ksort.c \
		ksort.c

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
