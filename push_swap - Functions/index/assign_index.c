/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:36:04 by ravazque          #+#    #+#             */
/*   Updated: 2024/12/04 21:49:33 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_idx(int size, t_stack **stack_a)
{
	int		*num_ord;
	int		*num_orig;
	t_stack	*temp;
	int		i;

	num_orig = array_pass(stack_a, size);
	if (!num_orig)
		return ;
	num_ord = array_pass(stack_a, size);
	if (!num_ord)
		return ;
	num_ord = bubble_sh(num_ord, size);
	idx_place(stack_a, size, num_ord, num_orig);
	temp = *stack_a;
	i = 0;
	while (temp)
	{
		temp->value = num_orig[i++];
		temp = temp->next;
	}
	// free(num_ord);
	// free(num_orig);
}

void	idx_place(t_stack **stack_a, int size, int *num_ord, int *num_orig)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (num_orig[i] != num_ord[j])
			j++;
		num_orig[i] = j;
		i++;
	}
}

int	*bubble_sh(int *num_ord, int size)
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

int	*array_pass(t_stack **stack_a, int size)
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
