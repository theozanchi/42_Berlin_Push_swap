/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost_calculation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:43:33 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 15:29:11 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Calculates the cost of puting indexes 'i_a' and 'i_b' on top of their
respective stack if one of them at least is equal to zero.
Returns a t_cost structure 'cost' that contains the most efficient operation to
perform.*/
void	handle_index_zero(size_t *i_a, size_t *i_b, t_info *info, t_cost *cost)
{
	if (*i_a == 0 && *i_b == 0)
	{
		cost->cost = 0;
		cost->ops = NO_MOVE;
		return ;
	}
	if (*i_a == 0)
	{
		cost->cost = ft_min(*i_b, info->b_length - *i_b);
		if (*i_b < info->b_length - *i_b)
			cost->ops = RB;
		else
			cost->ops = RRB;
		return ;
	}
	if (*i_b == 0)
	{
		cost->cost = ft_min(*i_a, info->a_length - *i_a);
		if (*i_a < info->a_length - *i_a)
			cost->ops = RA;
		else
			cost->ops = RRA;
	}
}

/*Calculates the cost of puting indexes 'i_a' and 'i_b' on top of their
respective stack by rotating both stacks before rotating a, b or none.
Returns a t_cost structure 'cost' that contains the most efficient operation to
perform.*/
void	handle_rr_r(size_t *i_a, size_t *i_b, t_cost *cost)
{
	cost->cost = ft_max(*i_a, *i_b);
	if (*i_a < *i_b)
		cost->ops = RR_RB;
	else if (*i_a == *i_b)
		cost->ops = RR;
	else
		cost->ops = RR_RA;
	cost->rotations_1 = ft_min(*i_a, *i_b);
	cost->rotations_2 = cost->cost - cost->rotations_1;
}

/*Calculates the cost of puting indexes 'i_a' and 'i_b' on top of their
respective stack by reverse rotating both stacks before rotating a, b or none.
Returns a t_cost structure 'cost' that contains the most efficient operation to
perform.*/
void	handle_rrr_rr(size_t *i_a, size_t *i_b, t_info *info, t_cost *cost)
{
	cost->cost = ft_max(info->a_length - *i_a, info->b_length - *i_b);
	if (info->a_length - *i_a < info->b_length - *i_b)
		cost->ops = RRR_RRB;
	else if (info->a_length - *i_a == info->b_length - *i_b)
		cost->ops = RRR;
	else
		cost->ops = RRR_RRA;
	cost->rotations_1 = ft_min(info->a_length - *i_a, info->b_length - *i_b);
	cost->rotations_2 = cost->cost - cost->rotations_1;
}

/*Calculates the cost of puting indexes 'i_a' and 'i_b' on top of their
respective stack by rotating stack a before reverse rotating stack b.
Returns a t_cost structure 'cost' that contains the most efficient operation to
perform.*/
void	handle_ra_rrb(size_t *i_a, size_t *i_b, t_info *info, t_cost *cost)
{
	cost->cost = *i_a + info->b_length - *i_b;
	cost->ops = RA_RRB;
	cost->rotations_1 = *i_a;
	cost->rotations_2 = info->b_length - *i_b;
}

/*Calculates the cost of puting indexes 'i_a' and 'i_b' on top of their
respective stack by reverse rotating stack a before rotating stack b.
Returns a t_cost structure 'cost' that contains the most efficient operation to
perform.*/
void	handle_rra_rb(size_t *i_a, size_t *i_b, t_info *info, t_cost *cost)
{
	cost->cost = info->a_length - *i_a + *i_b;
	cost->ops = RRA_RB;
	cost->rotations_1 = info->a_length - *i_a;
	cost->rotations_2 = *i_b;
}
