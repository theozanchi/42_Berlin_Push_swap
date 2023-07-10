/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:54:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 15:15:37 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Performs the operations listed in cost.ops on stacks a and b. First part of
the function deals with NO_MOVE, RA, RRA, RB, RRB, RR, RRR, RR_RA and RR_RB*/
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

/*Performs the operations listed in cost.ops on stacks a and b. Second part of
the function deals with RRR_RRA, RRR_RRB, RA_RRB and RRA_RB*/
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
