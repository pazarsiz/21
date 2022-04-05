/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:56 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 11:43:50 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	cmd_check(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 0);
	else
	{
		ft_exit_failure(2);
		return (-1);
	}
	return (0);
}

void	prompt_handler(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!(*line) || cmd_check(line, a, b) == -1)
		{
			free(line);
			break ;
		}
		free(line);
	}
	if (is_sorted_big(a) && b->count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	checker_handler(int size, long int *prime)
{
	t_stack		a;
	t_stack		b;

	a.arr = prime;
	a.size = size;
	a.count = a.size;
	if (size == 1 || is_sorted_big(&a))
		ft_exit_success(1);
	b.arr = malloc(sizeof(*prime) * size);
	b.size = size;
	b.count = 0;
	prompt_handler(&a, &b);
	free(b.arr);
}

int	main(int ac, char **av)
{
	long int	*arr;
	long int	*prime;

	arr = check_input(ac - 1, av);
	prime = simplify_array(ac - 1, arr);
	checker_handler(ac - 1, prime);
	free(arr);
	free(prime);
	return (0);
}
