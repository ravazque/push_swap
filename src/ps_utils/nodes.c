/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:34:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:13:15 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	*ft_add_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (NULL);
	}
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_insert_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*temp;

	new = ft_add_node(value);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	ft_max_node(t_stack **stack_a)
{
	t_stack	*temp;
	int		max;
	int		i;
	int		res;

	i = 0;
	temp = *stack_a;
	max = temp->value;
	res = 0;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			res = i;
		}
		temp = temp->next;
		i++;
	}
	return (res);
}
