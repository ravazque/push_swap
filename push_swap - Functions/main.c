
#include "push_swap.h"

t_stack	*crear_nodo(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		write(1, "Error al asignar memoria\n", 25);
		return (NULL);
	}
	new->value = value;
	new->next = NULL;
	return (new);
}

void	insertar_al_final(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*temp;

	new = crear_nodo(value);
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

void	imprimir_lista(t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

// -------------- main -----------------

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	int value;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
	{
		printf("Uso: %s <números>\n", argv[0]);
		return (1);
	}
	while (i < argc)
	{
		value = atoi(argv[i]);
		insertar_al_final(&stack_a, value);
		i++;
	}
	printf("Stack A antes de push_swap:\n");
	imprimir_lista(stack_a);
	push_swap(&stack_a, &stack_b);
	printf("Stack A después de push_swap:\n");
	imprimir_lista(stack_a);
	return (0);
}