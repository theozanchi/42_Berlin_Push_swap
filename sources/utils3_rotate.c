/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:48:00 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/16 17:47:34 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns the last element of the stack 's'*/
static t_stack	*get_stack_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

/*Shift up all elements of stack 's' by 1.
The first element becomes the last one.*/
static void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	last = get_stack_last(*s);
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

/*Shift up all elements of stack 'a' by 1 and print 'ra'
The first element becomes the last one.*/
void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

/*Shift up all elements of stack 'b' by 1 and print 'rb'
The first element becomes the last one.*/
void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

/*Shift up all elements of stacks 'a' and 'b' by 1 and print 'rr'
The first elements becomes the last ones.*/
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
