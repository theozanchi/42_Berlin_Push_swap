/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:19:31 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/03 17:49:16 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns the second last element of a stack 's'*/
t_stack	*get_second_last(t_stack *s)
{
	t_stack	*second_last;

	if (!s)
		return (NULL);
	while (s->next)
	{
		second_last = s;
		s = s->next;
	}
	return (second_last);
}

/*Returns the length of a stack 's'*/
size_t	get_stack_length(t_stack *s)
{
	size_t	length;

	length = 0;
	while (s)
	{
		length++;
		s = s->next;
	}
	return (length);
}

/*Runs through the stack and updates the index of each element*/
void	update_index(t_stack **s)
{
	size_t	index;
	t_stack	*ptr;

	index = 0;
	ptr = *s;
	while (ptr)
	{
		ptr->index = index++;
		ptr = ptr->next;
	}
}

static void	get_b_extrema(t_stack *b, t_stacks_info *info)
{
	int		min;
	size_t	min_index;
	int		max;
	size_t	max_index;

	min = INT_MAX;
	max = INT_MIN;
	while (b)
	{
		if (b->value < min)
		{
			min = b->value;
			min_index = b->index;
		}
		if (b->value > max)
		{
			max = b->value;
			max_index = b->index;
		}
		b = b->next;
	}
	info->b_min = min;
	info->b_min_index = min_index;
	info->b_max = max;
	info->b_max_index = max_index;
}

t_stacks_info	*get_stacks_info(t_stack **a, t_stack **b)
{
	t_stacks_info	*output;

	output = malloc(sizeof(t_stacks_info));
	if (!output)
		return (NULL);
	output->a_length = get_stack_length(*a);
	output->b_length = get_stack_length(*b);
	get_b_extrema(*b, output);
	return (output);
}
