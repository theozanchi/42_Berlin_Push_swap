/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:48:10 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/16 15:30:28 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swap the two first elements of the stack s if there are at least two elements
in it*/
void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

/*Swap the first 2 elements at the top of stack a and print 'sa'
Do nothing if there is only one or no elements*/
void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

/*Swap the first 2 elements at the top of stack b and print 'sb'
Do nothing if there is only one or no elements*/
void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}
