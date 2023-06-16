/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:48:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/16 17:16:44 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push adds the element 'new' at the beginning of the stack 's'*/
static void	push(t_stack **s, t_stack *new)
{
	if (!new)
		return ;
	new->next = *s;
	*s = new;
}

/*Take the first element at the top of b, put it at the top of a and print 'pa'
Do nothing if b is empty*/
void	pa(t_stack **a, t_stack **b)
{
	push(a, *b);
	ft_printf("pa\n");
}

/*Take the first element at the top of a, put it at the top of b and print 'pb'
Do nothing if b is empty*/
void	pb(t_stack **a, t_stack **b)
{
	push(b, *a);
	ft_printf("pb\n");
}
