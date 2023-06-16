/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:21:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/16 17:49:54 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	head->value = 42;
	head->index = 1;
	head->next = malloc(sizeof(t_stack));
	head->next->value = 43;
	head->next->index = 2;
	head->next->next = malloc(sizeof(t_stack));
	head->next->next->value = 44;
	head->next->next->index = 3;
	head->next->next->next = NULL;
	reverse_rotate(&head);
	while (head)
	{
		ft_printf("%i\n", head->value);
		head = head->next;
	}
}
