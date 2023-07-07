/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:57:39 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/07 14:34:43 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_pos_in_a(int value, t_stack *a, t_stacks_info *info)
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

size_t	get_pos_in_b(int value, t_stack *b, t_stacks_info *info)
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

t_cost	cost_calc(size_t index_a, size_t index_b, t_stacks_info info)
{
	t_cost	cost;
	size_t	temp_cost;

	if (index_a == 0 && index_b == 0)
	{
		cost.cost = 0;
		cost.ops = NO_MOVE;
		return (cost);
	}
	if (index_a == 0)
	{
		cost.cost = ft_min(index_b, info.b_length - index_b);
		if (index_b < info.b_length - index_b)
			cost.ops = RB;
		else
			cost.ops = RRB;
		return (cost);
	}
	if (index_b == 0)
	{
		cost.cost = ft_min(index_a, info.a_length - index_a);
		if (index_a < info.a_length - index_a)
			cost.ops = RA;
		else
			cost.ops = RRA;
		return (cost);
	}
	cost.cost = ft_max(index_a, index_b);
	if (index_a < index_b)
		cost.ops = RR_RB;
	else if (index_a == index_b)
		cost.ops = RR;
	else
		cost.ops = RR_RA;
	cost.rotations_1 = ft_min(index_a, index_b);
	cost.rotations_2 = cost.cost - cost.rotations_1;
	temp_cost = ft_max(info.a_length - index_a, info.b_length - index_b);
	if (temp_cost < cost.cost)
	{
		cost.cost = temp_cost;
		if (info.a_length - index_a < info.b_length - index_b)
			cost.ops = RRR_RRB;
		else if (info.a_length - index_a == info.b_length - index_b)
			cost.ops = RRR;
		else
			cost.ops = RRR_RRA;
		cost.rotations_1 = ft_min(info.a_length - index_a, info.b_length - index_b);
		cost.rotations_2 = cost.cost - cost.rotations_1;
	}
	temp_cost = index_a + info.b_length - index_b;
	if (temp_cost < cost.cost)
	{
		cost.cost = temp_cost;
		cost.ops = RA_RRB;
		cost.rotations_1 = index_a;
		cost.rotations_2 = info.b_length - index_b;
	}
	temp_cost = info.a_length - index_a + index_b;
	if (temp_cost < cost.cost)
	{
		cost.cost = temp_cost;
		cost.ops = RRA_RB;
		cost.rotations_1 = info.a_length - index_a;
		cost.rotations_2 = index_b;
	}
	return (cost);
}

void	push_from_a_to_b(t_stack **a, t_stack **b)
{
	t_stacks_info	*info;
	t_cost			cost;
	size_t			temp_cost;
	size_t			position;
	t_stack			*ptr;

	info = get_stacks_info(a, b);
	cost.cost = INT_MAX;
	ptr = *a;
	while (ptr)
	{
		position = get_pos_in_b(ptr->value, *b, info);
		temp_cost = cost_calc(ptr->index, position, *info).cost;
		if (temp_cost < cost.cost)
			cost = cost_calc(ptr->index, position, *info);
		if (cost.cost == 0)
			break ;
		ptr = ptr->next;
	}
	perform_rotations(a, b, cost);
	push(a, b, 'b', 1);
	free(info);
}
