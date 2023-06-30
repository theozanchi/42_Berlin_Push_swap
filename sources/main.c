/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:04 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 20:48:39 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Initialize stacks with the parameter string in a list. Each node is composed
of an integer, its index in the list and a pointer to next node
b is initialized and set to NULL
Returns the length of the stack created*/
size_t	init_stacks(t_stack **a, t_stack **b, char **argv)
{
	size_t	index;

	index = 0;
	*a = malloc(sizeof(t_stack));
	while (*argv)
	{
		*a = malloc(sizeof(t_stack));
		(*a)->value = ft_atoi(*argv++);
		(*a)->index = index++;
		a = &((*a)->next);
	}
	*b = malloc(sizeof(t_stack));
	*b = NULL;
	return (index);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;
	size_t	size;
	int		i;

	if (argc < 2 || !input_is_valid(argv + 1))
	{
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	size = init_stacks(&a, &b, argv + 1);
	i = 5;
	while (i--)
		push(&a, &b, 'b');
	rotate(&a, &b, 'b');
	ft_printf("\nStack A\n");
	temp = a;
	ft_printf("Value: ");
	while (a)
	{
		ft_printf("%d ", a->value);
		a = a->next;
	}
	a = temp;
	ft_printf("\nIndex: ");
	while (a)
	{
		ft_printf("%d ", a->index);
		a = a->next;
	}
	ft_printf("\n\nStack B\n");
	ft_printf("Value: ");
	temp = b;
	while (b)
	{
		ft_printf("%d ", b->value);
		b = b->next;
	}
	b = temp;
	ft_printf("\nIndex: ");
	while (b)
	{
		ft_printf("%d ", b->index);
		b = b->next;
	}
	return (0);
}
