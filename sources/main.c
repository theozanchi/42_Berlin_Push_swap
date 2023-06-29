/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:04 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/29 11:24:38 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **a, char **argv)
{
	int	index;

	index = 0;
	while (*argv)
	{
		*a = malloc(sizeof(t_stack));
		(*a)->value = ft_atoi(*argv++);
		(*a)->index = index++;
		(*a)->next = NULL;
		a = &((*a)->next);
	}
	*a = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !input_is_valid(argv))
	{
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	a = NULL;
	b = malloc(sizeof(t_stack));
	init_stack_a(&a, argv + 1);
	while (a && b)
	{
		ft_printf("%d, %d    %d, %d\n", a->value, a->index, b->value, b->index);
		a = a->next;
	}
	ft_printf("----    ----\n a       b");
	return (0);
}
