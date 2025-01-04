/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:54:30 by ravazque          #+#    #+#             */
/*   Updated: 2024/12/16 12:54:03 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_ordered(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
