/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:04:18 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/28 18:57:17 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	all_parameters_are_integers(char **argv)
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

static int	no_parameter_is_repeating(char **argv)
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

static int	parameters_are_not_already_sorted(char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (1);
		i++;
	}
	return (0);
}

int	input_is_valid(char **argv)
{
	if (all_parameters_are_integers(argv))
	{
		if (no_parameter_is_repeating(argv))
		{
			if (parameters_are_not_already_sorted(argv))
				return (1);
		}
	}
	return (0);
}
