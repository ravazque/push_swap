/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:43:39 by ravazque          #+#    #+#             */
/*   Updated: 2025/01/04 23:09:41 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "rb\n", 3);
}
