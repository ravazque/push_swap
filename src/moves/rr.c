/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:43:45 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:12:34 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*last_a;
	t_stack	*temp_b;
	t_stack	*last_b;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !stack_b || !(*stack_b)
		|| !(*stack_b)->next)
	{
		return ;
	}
	temp_a = *stack_a;
	*stack_a = temp_a->next;
	temp_a->next = NULL;
	last_a = *stack_a;
	while (last_a->next)
		last_a = last_a->next;
	last_a->next = temp_a;
	temp_b = *stack_b;
	*stack_b = temp_b->next;
	temp_b->next = NULL;
	last_b = *stack_b;
	while (last_b->next)
		last_b = last_b->next;
	last_b->next = temp_b;
	write(1, "rr\n", 3);
}
