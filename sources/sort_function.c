/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:53:45 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/07 14:52:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_of_three(t_stack **s)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = (*s)->value;
	i2 = (*s)->next->value;
	i3 = (*s)->next->next->value;
	if (i1 < i2)
	{
		if (i2 < i3)
			return ;
		else
		{
			reverse_rotate(s, s, 'a', 1);
			if (i1 < i3)
				swap(s, s, 'a');
		}
	}
	else
	{
		if (i2 < i3)
		{
			if (i1 < i3)
				swap(s, s, 'a');
			else
				rotate(s, s, 'a', 1);
		}
		else
		{
			swap(s, s, 'a');
			reverse_rotate(s, s, 'a', 1);
		}
	}
}

void	push_from_b_to_a(t_stack **a, t_stack **b)
{
	t_stacks_info	*info;
	t_cost			cost;
	size_t			temp_cost;
	size_t			position;
	t_stack			*ptr;

	info = get_stacks_info(a, b);
	cost.cost = INT_MAX;
	ptr = *b;
	while (ptr)
	{
		position = get_pos_in_a(ptr->value, *a, info);
		temp_cost = cost_calc(position, ptr->index, *info).cost;
		if (temp_cost < cost.cost)
			cost = cost_calc(position, ptr->index, *info);
		if (cost.cost == 0)
			break ;
		ptr = ptr->next;
	}
	perform_rotations(a, b, cost);
	push(a, b, 'a', 1);
	free(info);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	size_t			length;
	t_stacks_info	*info;

	length = get_stack_length(*a);
	if (length > 3)
		push(a, b, 'b', 2);
	length -= 2;
	while (length-- > 3)
		push_from_a_to_b(a, b);
	sort_stack_of_three(a);
	length = get_stack_length(*b);
	while (length--)
		push_from_b_to_a(a, b);
	info = get_stacks_info(a, b);
	if (info->a_min_index < info->a_length)
		rotate(a, b, 'a', info->a_min_index);
	else
		reverse_rotate(a, b, 'a', info->a_length - info->a_min_index);
}
