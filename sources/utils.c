/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:48:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 20:37:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Adds the element from one stack to the other (a->b or b->a) and prints the
operation*/
void	push(t_stack **a, t_stack **b, char a_or_b)
{
	t_stack	*temp;

	if (a_or_b == 'a' && *b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	if (a_or_b == 'b' && *a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	ft_printf("p%c\n", a_or_b);
}

/*Swap the two first elements of one or two stack depending on 'a_b_or_s'and
prints the operation*/
void	swap(t_stack **a, t_stack **b, char a_b_or_s)
{
	t_stack	*first;
	t_stack	*second;

	if ((a_b_or_s == 'a' || a_b_or_s == 's') && *a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if ((a_b_or_s == 'b' || a_b_or_s == 's') && *b && (*b)->next)
	{
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	ft_printf("s%c\n", a_b_or_s);
}

/*Returns the last element of a stack 's'*/
static t_stack	*get_second_last(t_stack *s)
{
	t_stack	*second_last;

	if (!s)
		return (NULL);
	while (s->next)
	{
		second_last = s;
		s = s->next;
	}
	return (second_last);
}

/*Shift up all elements of one or two stack depending on 'a_b_or_r' by 1.
The first element becomes the last one.*/
void	rotate(t_stack **a, t_stack **b, char a_b_or_r)
{
	t_stack	*first;
	t_stack	*last;

	if ((a_b_or_r == 'a' || a_b_or_r == 'r') && *a && (*a)->next)
	{
		first = *a;
		last = get_second_last(*a)->next;
		*a = first->next;
		first->next = NULL;
		last->next = first;
	}
	if ((a_b_or_r == 'b' || a_b_or_r == 'r') && *b && (*b)->next)
	{
		first = *b;
		last = get_second_last(*b)->next;
		*b = first->next;
		first->next = NULL;
		last->next = first;
	}
	ft_printf("r%c\n", a_b_or_r);
}

/*Shift down all elements of one or two stack depending on 'a_b_or_r' by 1.
The last element becomes the first one.*/
void	reverse_rotate(t_stack **a, t_stack **b, char a_b_or_r)
{
	t_stack	*second_last;
	t_stack	*last;


	if ((a_b_or_r == 'a' || a_b_or_r == 'r') && *a && (*a)->next)
	{
		second_last = get_second_last(*a);
		last = second_last->next;
		second_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	if ((a_b_or_r == 'b' || a_b_or_r == 'r') && *b && (*b)->next)
	{
		second_last = get_second_last(*b);
		last = second_last->next;
		second_last->next = NULL;
		last->next = *b;
		*b = last;
	}
	ft_printf("rr%c\n", a_b_or_r);
}
