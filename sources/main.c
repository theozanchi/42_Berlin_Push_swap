/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:04 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 16:36:17 by tzanchi          ###   ########.fr       */
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

	if (argc <= 2 || !input_is_valid(argv + 1))
	{
		ft_printf("%s", ERROR_MESSAGE);
		return (1);
	}
	init_stacks(&a, &b, argv, argc);
	sort_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

/*Initializes stacks with the parameter string in a list. Each node is composed
of an integer, its index in the list and a pointer to next node
b is initialized and set to NULL
Returns the length of the stack created*/
void	init_stacks(t_stack **a, t_stack **b, char **argv, int argc)
{
	t_stack	*new;

	*a = NULL;
	while (argc > 1)
	{
		new = malloc(sizeof(t_stack));
		new->value = ft_atoi(argv[argc - 1]);
		new->index = argc - 2;
		new->next = *a;
		*a = new;
		argc--;
	}
	*b = NULL;
}

/*Frees all nodes of the stack pointed by 'head' and sets it to NULL*/
void	free_stack(t_stack	**head)
{
	if (!head || !*head)
		return ;
	free_stack(&((*head)->next));
	free(*head);
	*head = NULL;
}
