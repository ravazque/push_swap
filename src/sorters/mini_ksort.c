/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ksort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:44:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:13:36 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ps_three_nodes(t_stack **stack_a)
{
	int	max_index;

	max_index = ft_max_node(stack_a);
	if (max_index == 1)
	{
		rra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	if (max_index == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	ra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	return ;
}

void	ps_four_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;

	max_index = ft_max_node(stack_a);
	if (max_index == 1)
		sa(stack_a);
	else if (max_index == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (max_index == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	ps_three_nodes(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
	return ;
}

void	ps_five_nodes(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;

	max_index = ft_max_node(stack_a);
	if (max_index == 1)
		sa(stack_a);
	else if (max_index == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (max_index == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (max_index == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	ps_four_nodes(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	return ;
}
