/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:57:39 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 15:02:56 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_from_a_to_b(t_stack **a, t_stack **b)
{
	t_info	info;
	t_cost	cost;
	size_t	temp_cost;
	size_t	position;
	t_stack	*ptr;

	info = get_stacks_info(a, b);
	cost.cost = INT_MAX;
	ptr = *a;
	while (ptr)
	{
		position = get_pos_in_b(ptr->value, *b, &info);
		temp_cost = cost_calc(ptr->index, position, info).cost;
		if (temp_cost < cost.cost)
			cost = cost_calc(ptr->index, position, info);
		if (cost.cost == 0)
			break ;
		ptr = ptr->next;
	}
	perform_rotations(a, b, cost);
	push(a, b, 'b', 1);
}

void	push_from_b_to_a(t_stack **a, t_stack **b)
{
	t_info	info;
	t_cost	cost;
	size_t	temp_cost;
	size_t	position;
	t_stack	*ptr;

	info = get_stacks_info(a, b);
	cost.cost = INT_MAX;
	ptr = *b;
	while (ptr)
	{
		position = get_pos_in_a(ptr->value, *a, &info);
		temp_cost = cost_calc(position, ptr->index, info).cost;
		if (temp_cost < cost.cost)
			cost = cost_calc(position, ptr->index, info);
		if (cost.cost == 0)
			break ;
		ptr = ptr->next;
	}
	perform_rotations(a, b, cost);
	push(a, b, 'a', 1);
}

size_t	get_pos_in_a(int value, t_stack *a, t_info *info)
{
	size_t	position;

	if (value > info->a_max)
		position = info->a_max_index + 1;
	else if (value < info->a_min)
		position = info->a_min_index;
	else
	{
		while (a->next)
		{
			position = a->next->index;
			if (value > a->value && value < a->next->value)
				break ;
			a = a->next;
		}
		if (!a->next)
			position++;
	}
	if (position == info->a_length)
		position = 0;
	return (position);
}

size_t	get_pos_in_b(int value, t_stack *b, t_info *info)
{
	size_t	position;

	if (value > info->b_max)
		position = info->b_min_index + 1;
	else if (value < info->b_min)
		position = info->b_max_index;
	else
	{
		while (b->next)
		{
			position = b->next->index;
			if (value < b->value && value > b->next->value)
				break ;
			b = b->next;
		}
		if (!b->next)
			position++;
	}
	if (position == info->b_length)
		position = 0;
	return (position);
}

t_cost	cost_calc(size_t index_a, size_t index_b, t_info info)
{
	t_cost	cost;

	if (index_a == 0 || index_b == 0)
	{
		handle_index_zero(&index_a, &index_b, &info, &cost);
		return (cost);
	}
	handle_rr_r(&index_a, &index_b, &cost);
	if ((size_t)ft_max(info.a_length - index_a, info.b_length - index_b)
		< cost.cost)
		handle_rrr_rr(&index_a, &index_b, &info, &cost);
	if (index_a + info.b_length - index_b < cost.cost)
		handle_ra_rrb(&index_a, &index_b, &info, &cost);
	if (info.a_length - index_a + index_b < cost.cost)
		handle_rra_rb(&index_a, &index_b, &info, &cost);
	return (cost);
}
