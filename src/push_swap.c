/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:41:56 by ravazque          #+#    #+#             */
/*   Updated: 2025/06/26 18:12:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_duplicates(t_stack *stack_a)
{
	t_stack	*reference;
	t_stack	*temp;

	reference = stack_a;
	while (reference)
	{
		temp = reference->next;
		while (temp)
		{
			if (temp->value == reference->value)
			{
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			temp = temp->next;
		}
		reference = reference->next;
	}
	return (0);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 5 && ft_check_ordered(stack_a) != 0)
		ps_five_nodes(stack_a, stack_b);
	else if (size == 4 && ft_check_ordered(stack_a) != 0)
		ps_four_nodes(stack_a, stack_b);
	else if (size == 3 && ft_check_ordered(stack_a) != 0)
		ps_three_nodes(stack_a);
	else if (size == 2 && ft_check_ordered(stack_a) != 0)
		ft_simple_sort(stack_a);
	return ;
}

static int	process_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	j;
	int	value;
	int	size;

	i = 1;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		j = 0;
		size = ft_lstsize(*stack_a);
		while (argv[i][j] != '\0')
		{
			if (ft_atoi(argv[i], &value, &j) == NULL)
				return (write(STDERR_FILENO, "Error\n", 6), 0);
			ft_insert_node(stack_a, value);
		}
		if (size == ft_lstsize(*stack_a))
			return (write(STDERR_FILENO, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (check_duplicates(*stack_a))
		return ;
	ft_assign_idx(ft_lstsize(*stack_a), stack_a);
	if (ft_lstsize(*stack_a) > 500)
		return ;
	else if (ft_lstsize(*stack_a) > 5)
		ksort(stack_a, stack_b);
	else
		sort_stack(stack_a, stack_b);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!process_arguments(argc, argv, &stack_a))
		return (0);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
