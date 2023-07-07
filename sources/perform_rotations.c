/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:54:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/07 15:05:02 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_rotations(t_stack **a, t_stack **b, t_cost cost)
{
	if (cost.ops == RA)
		rotate(a, b, 'a', cost.cost);
	if (cost.ops == RRA)
		reverse_rotate(a, b, 'a', cost.cost);
	if (cost.ops == RB)
		rotate(a, b, 'b', cost.cost);
	if (cost.ops == RRB)
		reverse_rotate(a, b, 'b', cost.cost);
	if (cost.ops == RR)
		rotate(a, b, 'r', cost.cost);
	if (cost.ops == RRR)
		reverse_rotate(a, b, 'r', cost.cost);
	if (cost.ops == RR_RA || cost.ops == RR_RB)
	{
		rotate(a, b, 'r', cost.rotations_1);
		if (cost.ops == RR_RA)
			rotate(a, b, 'a', cost.rotations_2);
		else
			rotate(a, b, 'b', cost.rotations_2);
	}
	if (cost.ops >= 9)
		perform_rotations_2(a, b, cost);
}

void	perform_rotations_2(t_stack **a, t_stack **b, t_cost cost)
{
	if (cost.ops == RRR_RRA || cost.ops == RRR_RRB)
	{
		reverse_rotate(a, b, 'r', cost.rotations_1);
		if (cost.ops == RRR_RRA)
			reverse_rotate(a, b, 'a', cost.rotations_2);
		else
			reverse_rotate(a, b, 'b', cost.rotations_2);
	}
	if (cost.ops == RA_RRB)
	{
		rotate(a, b, 'a', cost.rotations_1);
		reverse_rotate(a, b, 'b', cost.rotations_2);
	}
	if (cost.ops == RRA_RB)
	{
		reverse_rotate(a, b, 'a', cost.rotations_1);
		rotate(a, b, 'b', cost.rotations_2);
	}
}
