/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:04:18 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 17:56:01 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns 1 if all the parameters of argv are digits*/
int	all_parameters_are_integers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*Returns 1 if all the parameters of argv are distinct*/
int	no_parameter_is_repeating(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*Returns 1 if the input is valid:
• All the parameters are numbers
• All the parameters are distinct
• The stack is not already sorted*/
int	input_is_valid(char **argv)
{
	if (all_parameters_are_integers(argv))
	{
		if (no_parameter_is_repeating(argv))
			return (1);
	}
	return (0);
}

/*Returns 1 if the stack is already sorted*/
int	stack_is_already_sorted(t_stack *s)
{
	while (s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}
