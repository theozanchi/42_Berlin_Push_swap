/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:04 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 17:15:16 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if arguments are valid and returns 'Error\n' if not. Sorts stack a
using standard push, swap, rotate and reverse rotate functions, and prints the
list of operations needed to sort stack a. Frees both stacks*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 2)
		return (0);
	if (!input_is_valid(argv + 1))
	{
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	if (init_stacks(&a, &b, argv, argc) == 1)
	{
		free_stack(&a);
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	else
	{
		sort_stacks(&a, &b);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
}

/*Initializes stacks with the parameter string in a list. Each node is composed
of an integer, its index in the list and a pointer to next node
b is initialized and set to NULL
If any number is invalid (negative or bigger than INT_MAX), it stops and
returns 1*/
int	init_stacks(t_stack **a, t_stack **b, char **argv, int argc)
{
	t_stack	*new;

	*a = NULL;
	while (argc > 1)
	{
		new = malloc(sizeof(t_stack));
		if (ft_atol(argv[argc - 1]) < 0 || ft_atol(argv[argc - 1]) > INT_MAX)
			return (1);
		new->value = ft_atoi(argv[argc - 1]);
		new->index = argc - 2;
		new->next = *a;
		*a = new;
		argc--;
	}
	*b = NULL;
	return (0);
}

/*Frees all nodes of the stack pointed by 'head' and sets it to NULL*/
void	free_stack(t_stack	**head)
{
	t_stack	*current;
	t_stack	*next;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
