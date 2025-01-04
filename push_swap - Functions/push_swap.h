/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:07:23 by ravazque          #+#    #+#             */
/*   Updated: 2025/01/03 13:58:24 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
}					t_stack;

//---------------------------------------------------------------------

int					*ft_atoi(const char *nptr, int *res, int *index);
int					ft_lstsize(t_stack *lst);
int					ft_max_node(t_stack **stack_a);
int					ft_check_ordered(t_stack **stack_a);
void				ft_insert_node(t_stack **stack, int value);
void				ft_assign_idx(int size, t_stack **stack_a);
void				ksort(t_stack **stack_a, t_stack **stack_b);
void				ft_lstclear(t_stack **lst);
void				ft_lstdelone(t_stack *lst);
int					ft_lstpos(t_stack *head, int position);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

//---------------------------------------------------------------------

void				ft_simple_sort(t_stack **stack_a);
void				ps_three_nodes(t_stack **stack_a);
void				ps_four_nodes(t_stack **stack_a, t_stack **stack_b);
void				ps_five_nodes(t_stack **stack_a, t_stack **stack_b);

//---------------------------------------------------------------------

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

//---------------------------------------------------------------------

#endif
