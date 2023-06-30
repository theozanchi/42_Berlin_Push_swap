/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:03:27 by tzanchi           #+#    #+#             */
/*   Updated: 2023/06/30 21:34:30 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ERROR_MESSAGE "Error\n"

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*next;
}	t_stack;

/*input_validation*/
int		input_is_valid(char **argv);

/*utils_stack_manip*/
t_stack	*get_second_last(t_stack *s);
size_t	get_stack_length(t_stack *s);
void	update_index(t_stack **s);

/*utils_standard*/
void	push(t_stack **a, t_stack **b, char a_or_b);
void	swap(t_stack **a, t_stack **b, char a_b_or_s);
void	rotate(t_stack **a, t_stack **b, char a_b_or_r);
void	reverse_rotate(t_stack **a, t_stack **b, char a_b_or_r);

#endif
