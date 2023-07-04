/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:03:27 by tzanchi           #+#    #+#             */
/*   Updated: 2023/07/04 17:29:07 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ERROR_MESSAGE "Error\n"

# define NO_MOVE 0
# define RA 1
# define RRA 2
# define RB 3
# define RRB 4
# define RR 5
# define RRR 6
# define RR_RA 7
# define RR_RB 8
# define RRR_RRA 9
# define RRR_RRB 10
# define RA_RRB 11
# define RRA_RB 12

typedef struct s_stack
{
	int				value;
	size_t			index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks_info
{
	size_t	a_length;
	size_t	b_length;
	int		b_min;
	size_t	b_min_index;
	int		b_max;
	size_t	b_max_index;
}	t_stacks_info;

typedef struct s_cost
{
	size_t	cost;
	int		ops;
	int		rotations_1;
	int		rotations_2;
}	t_cost;

/*cost_calculation*/
void			find_best_element_to_move(t_stack **a, t_stack **b);

/*free*/
void			free_stack(t_stack	**head);

/*input_validation*/
int				input_is_valid(char **argv);

/*perform_operations*/
void			perform_ops(t_stack **a, t_stack **b, t_cost cost);

/*sort_function*/
void			sort_stacks(t_stack **a, t_stack **b);

/*utils_stack_manip*/
t_stack			*get_second_last(t_stack *s);
size_t			get_stack_length(t_stack *s);
void			update_index(t_stack **s);
t_stacks_info	*get_stacks_info(t_stack **a, t_stack **b);

/*utils_standard*/
void			push(t_stack **a, t_stack **b, char a_or_b, int times);
void			swap(t_stack **a, t_stack **b, char a_b_or_s);
void			rotate(t_stack **a, t_stack **b, char a_b_or_r, int times);
void			reverse_rotate(t_stack **a, t_stack **b, char a_b_or_r, int times);

#endif
