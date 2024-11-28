/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:55:38 by ravazque          #+#    #+#             */
/*   Updated: 2024/11/28 15:55:55 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertar_al_final(t_stack **stack, int value)
{
    t_stack *new;
    t_stack *temp;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return ;
    new->value = value;
    new->next = NULL;
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

void imprimir_lista(t_stack *stack)
{
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

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
		printf("Uso: %s <valuees>\n", argv[0]);
		return (1);
	}
	while (i < argc)
	{
		insertar_al_final(&stack_a, atoi(argv[i]));
		i++;
	}
	
	// printf("\n--------------------------\nPila A inicial:\n- ");
	// imprimir_lista(stack_a);
	// printf("\nPila B inicial:\n- ");
	// imprimir_lista(stack_b);
	// printf("--------------------------\n\n- Ejecutando sa (swap A) -\n");
	// sa(&stack_a);
	// imprimir_lista(stack_a);
	// printf("\n- Ejecutando sb (swap B) ---\n");
	// sb(&stack_b);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando ss (swap A y B simultáneo) -\n");
	// ss(&stack_a, &stack_b);
	// imprimir_lista(stack_a);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando pb (push A a B) -\n");
	// pb(&stack_a, &stack_b);
	// imprimir_lista(stack_a);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando pa (push B a A) -\n");
	// pa(&stack_a, &stack_b);
	// imprimir_lista(stack_a);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando ra (rotate A) -\n");
	// ra(&stack_a);
	// imprimir_lista(stack_a);
	// printf("\n- Ejecutando rb (rotate B) -\n");
	// rb(&stack_b);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando rr (rotate A y B simultáneo) -\n");
	// rr(&stack_a, &stack_b);
	// imprimir_lista(stack_a);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando rra (reverse rotate A) -\n");
	// rra(&stack_a);
	// imprimir_lista(stack_a);
	// printf("\n- Ejecutando rrb (reverse rotate B) -\n");
	// rrb(&stack_b);
	// imprimir_lista(stack_b);
	// printf("\n- Ejecutando rrr (reverse rotate A y B simultáneo) -\n");
	// rrr(&stack_a, &stack_b);
	// imprimir_lista(stack_a);
	// imprimir_lista(stack_b);
	// return (0);
	
}
