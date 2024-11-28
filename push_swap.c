/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:30 by ravazque          #+#    #+#             */
/*   Updated: 2024/11/28 15:24:14 by ravazque         ###   ########.fr       */
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

//-----------------------------------------------------------

// ------------------------ main ----------------------------

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
	{
		printf("Uso: %s <valores>\n", argv[0]);
		return (1);
	}
	while (i < argc)
	{
		insertar_al_final(&stack_a, atoi(argv[i]));
		i++;
	}
	printf("\nPila A inicial:\n");
	imprimir_lista(stack_a);
	printf("Pila B inicial:\n");
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando sa (swap A) ---\n");
	sa(&stack_a);
	imprimir_lista(stack_a);
	printf("\n--- Ejecutando sb (swap B) ---\n");
	sb(&stack_b);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando ss (swap A y B simultáneo) ---\n");
	ss(&stack_a, &stack_b);
	imprimir_lista(stack_a);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando pb (push A a B) ---\n");
	pb(&stack_a, &stack_b);
	imprimir_lista(stack_a);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando pa (push B a A) ---\n");
	pa(&stack_a, &stack_b);
	imprimir_lista(stack_a);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando ra (rotate A) ---\n");
	ra(&stack_a);
	imprimir_lista(stack_a);
	printf("\n--- Ejecutando rb (rotate B) ---\n");
	rb(&stack_b);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando rr (rotate A y B simultáneo) ---\n");
	rr(&stack_a, &stack_b);
	imprimir_lista(stack_a);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando rra (reverse rotate A) ---\n");
	rra(&stack_a);
	imprimir_lista(stack_a);
	printf("\n--- Ejecutando rrb (reverse rotate B) ---\n");
	rrb(&stack_b);
	imprimir_lista(stack_b);
	printf("\n--- Ejecutando rrr (reverse rotate A y B simultáneo) ---\n");
	rrr(&stack_a, &stack_b);
	imprimir_lista(stack_a);
	imprimir_lista(stack_b);
	return (0);
}
