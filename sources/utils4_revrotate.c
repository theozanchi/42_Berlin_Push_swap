/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_revrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:31:38 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/16 17:52:37 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Shift down all elements of stack 's' by 1.
The last element becomes the first one.*/
static void	reverse_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*s || !(*s)->next)
		return ;
	second_last = *s;
	last = (*s)->next;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *s;
	*s = last;
}

/*Shift down all elements of stack a by 1 and print 'rra'
The last element becomes the first one*/
void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

/*Shift down all elements of stack b by 1 and print 'rrb'
The last element becomes the first one*/
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

/*Shift down all elements of stacks a and b by 1 and print 'rrr'
The last elements become the first ones*/
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrb\n");
}
