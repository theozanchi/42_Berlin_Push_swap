/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:03:27 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 20:15:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ERROR_MESSAGE "Error\n"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/*input_validation*/
int		input_is_valid(char **argv);

/*utils*/
void	push(t_stack **a, t_stack **b, char c);
void	swap(t_stack **a, t_stack **b, char c);
void	rotate(t_stack **a, t_stack **b, char c);
void	reverse_rotate(t_stack **a, t_stack **b, char c);

#endif
