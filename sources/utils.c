/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:48:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 20:09:07 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns the last element of a stack 's'*/
static t_stack	*get_stack_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

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

/*Swap the two first elements of one or two stack depending on 'c'and
prints the operation*/
void	swap(t_stack **a, t_stack **b, char c)
{
	t_stack	*first;
	t_stack	*second;

	if ((c == 'a' || c == 's') && *a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if ((c == 'b' || c == 's') && *b && (*b)->next)
	{
		first = *b;
		second = (*b)->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	ft_printf("s%c\n", c);
}

/*Shift up all elements of one or two stack depending on 'c' by 1.
The first element becomes the last one.*/
void	rotate(t_stack **a, t_stack **b, char c)
{
	t_stack	*first;
	t_stack	*last;

	if ((c == 'a' || c == 'r') && *a && (*a)->next)
	{
		first = *a;
		last = get_stack_last(*a);
		*a = first->next;
		first->next = NULL;
		last->next = first;
	}
	if ((c == 'b' || c == 'r') && *b && (*b)->next)
	{
		first = *b;
		last = get_stack_last(*b);
		*b = first->next;
		first->next = NULL;
		last->next = first;
	}
	ft_printf("r%c\n", c);
}

/*Shift down all elements of one or two stack depending on 'c' by 1.
The last element becomes the first one.*/
void	reverse_rotate(t_stack **a, t_stack **b, char c)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((c == 'a' || c == 'r') && *a && (*a)->next)
	{
		second_last = *a;
		last = (*a)->next;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	if ((c == 'b' || c == 'r') && *b && (*b)->next)
	{
		second_last = *b;
		last = (*b)->next;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *b;
		*b = last;
	}
	ft_printf("rr%c\n", c);
}
