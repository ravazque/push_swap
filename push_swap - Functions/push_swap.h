/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:07:23 by ravazque          #+#    #+#             */
/*   Updated: 2024/12/04 21:55:42 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "_libft/libft.h"
# include "_printf/ft_printf.h"

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

//---------------------------------------------------------------------

void				push_swap(t_stack **stack_a, t_stack **stack_b);
void				assign_idx(int size, t_stack **stack_a);
int					*array_pass(t_stack **stack_a, int size);
int					*bubble_sh(int *num_ord, int size);
void				idx_place(t_stack **stack_a, int size, int *num_ord, int *num_orig);

//---------------------------------------------------------------------

t_stack				*crear_nodo(int value);
void				insertar_al_final(t_stack **head, int value);
void				imprimir_lista(t_stack *head);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif

//---------------------------------------------------------------------

