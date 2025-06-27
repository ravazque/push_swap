/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:36:04 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:12:57 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	idx_place(t_stack **stack_a, int size, int *num_ord)
{
	int		i;
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (num_ord[i] == temp->value)
			{
				temp->value = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

static int	*b_sort(int *num_ord, int size)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = -1;
	while (++i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (num_ord[j] > num_ord[j + 1])
			{
				temp = num_ord[j];
				num_ord[j] = num_ord[j + 1];
				num_ord[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
	}
	return (num_ord);
}

static int	*array_pass(t_stack **stack_a, int size)
{
	int		*num_ord;
	t_stack	*temp;
	int		i;

	num_ord = (int *)malloc(size * sizeof(int));
	if (!num_ord)
		return (NULL);
	temp = *stack_a;
	i = 0;
	while (temp)
	{
		num_ord[i++] = temp->value;
		temp = temp->next;
	}
	return (num_ord);
}

void	ft_assign_idx(int size, t_stack **stack_a)
{
	int	*num_ord;

	num_ord = array_pass(stack_a, size);
	if (!num_ord)
		return ;
	num_ord = b_sort(num_ord, size);
	idx_place(stack_a, size, num_ord);
	free(num_ord);
}
