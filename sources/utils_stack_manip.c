/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:19:31 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 21:39:55 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns the second last element of a stack 's'*/
t_stack	*get_second_last(t_stack *s)
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

/*Returns the length of a stack 's'*/
size_t	get_stack_length(t_stack *s)
{
	size_t	length;

	length = 0;
	while (s)
	{
		length++;
		s = s->next;
	}
	return (length);
}

/*Runs through the stack and updates the index of each element*/
void	update_index(t_stack **s)
{
	size_t	index;
	t_stack	*ptr;

	index = 0;
	ptr = *s;
	while (ptr)
	{
		ptr->index = index++;
		ptr = ptr->next;
	}
}
