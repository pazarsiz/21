/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:38:01 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 16:20:57 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

//structure for stacks A & B
typedef struct s_stack
{
	int			size;
	int			count;
	long int	*arr;
}	t_stack;

long int	*check_input(int ac, char **av);
long int	*simplify_array(int ac, long int *arr);
long int	*turn_to_primes(int ac, long int *arr, long int *tmp);

// base function for process the arguments
//int	process_args(int ac, char **av);

//base & simple sorting functions
int			sort_stacks(int ac, long int *arr);
int			sort_start(t_stack *a, t_stack *b);
int			sort_two(t_stack *x);

//sort three functions
int			sort_three(t_stack *x);
int			sort_three_123_132_231(t_stack *x);
int			sort_three_321_213_312(t_stack *x);

//sort five functions
int			sort_five(t_stack *a, t_stack *b);

//push_swap operations
int			sa(t_stack *x, int flag);
int			ra(t_stack *x, int flag);
int			rra(t_stack *x, int flag);
int			pb(t_stack *a, t_stack *b, int flag);
int			pa(t_stack *a, t_stack *b, int flag);

//radix sorting functions
int			sort_big(t_stack *a, t_stack *b);

//stack functions
void		show_stack(t_stack *x);
int			is_sorted_big(t_stack *x);

//checker
char		*get_next_line(int fd);

#endif
