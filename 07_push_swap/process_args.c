/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:08:33 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/01 16:51:06 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_args(int size, char **av)
{
	long int	*arr;

	arr = check_input(size, av);
	if (size == 1)
		exit(EXIT_SUCCESS);
	sort_stacks(size, arr);
	free(arr);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit(EXIT_SUCCESS);
	process_args(ac - 1, av);
	exit(EXIT_SUCCESS);
	return (0);
}
