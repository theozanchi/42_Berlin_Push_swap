/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:57:39 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/04 17:29:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_pos_in_b(int value, t_stack *b)
{
	if (value < b->value)
		return (b->index);
	while (b->next)
	{
		if (value > b->value && value < b->next->value)
			break ;
	}
	return (b->next->index);
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
		cost.ops = RR_RA;
	else if (index_a == index_b)
		cost.ops = RR;
	else
		cost.ops = RR_RB;
	cost.rotations_1 = ft_min(index_a, index_b);
	cost.rotations_2 = cost.cost - cost.rotations_1;
	temp_cost = ft_max(info.a_length - index_a, info.b_length - index_b);
	if (temp_cost < cost.cost)
	{
		cost.cost = temp_cost;
		if (info.a_length - index_a < info.b_length - index_b)
			cost.ops = RRR_RRA;
		else if (info.a_length - index_a == info.b_length - index_b)
			cost.ops = RRR;
		else
			cost.ops = RRR_RRB;
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

void	find_best_element_to_move(t_stack **a, t_stack **b)
{
	t_stacks_info	*info;
	t_cost			cost;
	size_t			temp_cost;
	size_t			position;

	info = get_stacks_info(a, b);
	cost.cost = INT_MAX;
	while (*a)
	{
		position = get_pos_in_b((*a)->value, *b);
		temp_cost = cost_calc((*a)->index, position, *info).cost;
		if (temp_cost < cost.cost)
			cost = cost_calc((*a)->index, position, *info);
		if (cost.cost == 1)
			break ;
		*a = (*a)->next;
	}
	perform_ops(a, b, cost);
	free(info);
}
