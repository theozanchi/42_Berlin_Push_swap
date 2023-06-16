/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:21:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/16 15:58:59 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s);

int	main(void)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	head->value = 4200;
	head->index = 1;
	head->next = malloc(sizeof(t_stack));
	head->next->value = 2400;
	head->next->index = 2;
	head->next->next = NULL;
	swap(&head);
	while (head)
	{
		ft_printf("%i\n", head->value);
		head = head->next;
	}
}
