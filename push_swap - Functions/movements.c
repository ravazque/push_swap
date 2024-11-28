/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:30 by ravazque          #+#    #+#             */
/*   Updated: 2024/11/28 15:55:24 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Intercambia el primer y segundo nodo de la pila A.
void	sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

// Intercambia el primer y segundo nodo de la pila B.
void	sb(t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

// Ejecuta sa y sb simultáneamente.
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// Mueve el primer nodo de la pila B a la pila A.
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

// Mueve el primer nodo de la pila A a la pila B.
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

// Mueve el primer nodo de la pila A al final de la pila.
void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = temp;
}

// Mueve el primer nodo de la pila B al final de la pila.
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
}

// Ejecuta ra y rb simultáneamente.
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

// Mueve el último nodo de la pila A al principio.
void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*previous;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	previous = NULL;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

// Mueve el último nodo de la pila B al principio.
void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*previous;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	previous = NULL;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

// Ejecuta rra y rrb simultáneamente.
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
