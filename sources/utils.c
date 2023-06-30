/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:48:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 18:32:34 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Adds the element from one stack to the other (a->b or b->a) and prints the
operation*/
void	push(t_stack **a, t_stack **b, char c)
{
	t_stack	*temp;

	if (c == 'a' && *b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	if (c == 'b' && *a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	ft_printf("p%c\n", c);
}

/*Swap the two first elements of one or twio stack depending on 'c'and
prints the operation*/
void	swap(t_stack **a, t_stack **b, char c)
{
	t_stack	*first;
	t_stack	*second;

	if (c == 'a' || c == 's')
	{
		if (!*a || !(*a)->next)
			return ;
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if (c == 'b' || c == 's')
	{
		if (!*b || !(*b)->next)
			return ;
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	ft_printf("s%c\n", c);
}
