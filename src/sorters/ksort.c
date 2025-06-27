/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:53:35 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:13:25 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_sqrt(int nbr)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1;
	while (i * i <= nbr)
		i++;
	return (i - 1);
}

static void	push_to_b(t_stack **list_a, t_stack **list_b, int *size_a,
	int *size_b)
{
	int	range;

	range = get_sqrt(*size_a) * 133 / 100;
	while (*size_a > 0)
	{
		if ((*list_a)->value <= *size_b)
		{
			pb(list_a, list_b);
			(*size_a)--;
			(*size_b)++;
		}
		else if ((*list_a)->value <= *size_b + range)
		{
			pb(list_a, list_b);
			(*size_a)--;
			(*size_b)++;
			if (!((*list_a)->value <= *size_b + range))
				rr(list_a, list_b);
			else
				rb(list_b);
		}
		else
			ra(list_a);
	}
}

static void	push_to_a(t_stack **list_a, t_stack **list_b, int *size_a,
	int *size_b)
{
	while (*size_b > 0)
	{
		while ((*list_b)->value != *size_b - 1)
		{
			if (ft_lstpos(*list_b, *size_b - 1) <= *size_b / 2)
				rb(list_b);
			else
				rrb(list_b);
		}
		pa(list_a, list_b);
		(*size_a)++;
		(*size_b)--;
	}
}

void	ksort(t_stack **list_a, t_stack **list_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*list_a);
	size_b = ft_lstsize(*list_b);
	push_to_b(list_a, list_b, &size_a, &size_b);
	push_to_a(list_a, list_b, &size_a, &size_b);
}
