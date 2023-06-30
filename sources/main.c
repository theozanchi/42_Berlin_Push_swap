/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:04 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 19:25:14 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Initialize stack with the parameter string in a list. Each node is composed
of an integer, its index in the list and a pointer to next node
Returns the length of the list*/
size_t	init_stack_a(t_stack **a, char **argv)
{
	size_t	index;

	index = 0;
	while (*argv)
	{
		*a = malloc(sizeof(t_stack));
		(*a)->value = ft_atoi(*argv++);
		(*a)->index = index++;
		a = &((*a)->next);
	}
	return (index);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	size_t	size;

	if (argc < 2 || !input_is_valid(argv + 1))
	{
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	b = NULL;
	size = init_stack_a(&a, argv + 1);
	while (a)
		push(&a, &b, 'b');
	swap(&a, &b, 'b');
	while (b)
	{
		ft_printf("%d ", b->value);
		b = b->next;
	}
	return (0);
}
