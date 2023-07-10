/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:53:45 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/10 15:26:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Pushes all elements from a to b so that b always remains sorted in descending
order until 3 elements remain in a.
Sorts the three elements in a using a dedicated function.
Pushes back all elements from b to a at the correct position so that a remains
sorted in ascending order.
Rotates or reverse rotates a to put the min on top of the stack.*/
void	sort_stacks(t_stack **a, t_stack **b)
{
	size_t	length;

	length = get_stack_length(*a);
	if (length == 2)
	{
		swap(a, b, 'a');
		return ;
	}
	if (length > 3)
		push(a, b, 'b', 2);
	length -= 2;
	while (length-- > 3)
		push_from_a_to_b(a, b);
	sort_stack_of_three(a);
	if (*b)
	{
		length = get_stack_length(*b);
		while (length--)
			push_from_b_to_a(a, b);
	}
	put_a_in_ascending_order(a, b);
}

/*Sorts a stack of three elements in ascending order by performing one or two
operations only.*/
void	sort_stack_of_three(t_stack **s)
{
	if ((*s)->value < (*s)->next->value
		&& (*s)->next->value < (*s)->next->next->value)
		return ;
	if ((*s)->value < (*s)->next->value
		&& (*s)->value < (*s)->next->next->value)
	{
		reverse_rotate(s, s, 'a', 1);
		swap(s, s, 'a');
	}
	else if ((*s)->value > (*s)->next->value
		&& (*s)->value > (*s)->next->next->value)
	{
		rotate(s, s, 'a', 1);
		if (!((*s)->value < (*s)->next->value
				&& (*s)->next->value < (*s)->next->next->value))
			swap(s, s, 'a');
	}
	else
	{
		if ((*s)->next->value > (*s)->value
			&& (*s)->next->value > (*s)->next->next->value)
			reverse_rotate(s, s, 'a', 1);
		else
			swap(s, s, 'a');
	}
}

/*Rotates or reverse rotates a to put the min on top of the stack*/
void	put_a_in_ascending_order(t_stack **a, t_stack **b)
{
	t_info	info;

	info = get_stacks_info(a, b);
	if (info.a_min_index != 0)
	{
		if (info.a_min_index < info.a_length)
			rotate(a, b, 'a', info.a_min_index);
		else
			reverse_rotate(a, b, 'a', info.a_length - info.a_min_index);
	}
}
