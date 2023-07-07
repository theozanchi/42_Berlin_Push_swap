/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:04 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/07 15:06:28 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !input_is_valid(argv + 1))
	{
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	init_stacks(&a, &b, argv + 1);
	sort_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

/*Initialize stacks with the parameter string in a list. Each node is composed
of an integer, its index in the list and a pointer to next node
b is initialized and set to NULL
Returns the length of the stack created*/
void	init_stacks(t_stack **a, t_stack **b, char **argv)
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
}

void	free_stack(t_stack	**head)
{
	if (!head || !*head)
		return ;
	free_stack(&((*head)->next));
	free(*head);
	*head = NULL;
}
