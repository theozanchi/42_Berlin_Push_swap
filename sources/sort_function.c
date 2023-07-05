/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:53:45 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/05 14:39:53 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*1. Loop through a and calculate the cost for each element
  2. Do the operation that is the most efficient
  3. Push back everything to b*/
void	sort_stacks(t_stack **a, t_stack **b)
{
	size_t	length;

	push(a, b, 'b', 2);
	length = get_stack_length(*a);
	while (length-- > 3)
		find_best_element_to_move(a, b);
}
