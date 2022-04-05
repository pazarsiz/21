/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:43:58 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 16:17:57 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	get_long_result(long int result, int count)
{
	int	znak;

	if (count % 2 != 0)
		znak = -1;
	else
		znak = 1;
	return (result * znak);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			count;
	long int	result;

	i = 0;
	count = 0;
	result = 0;
	while (str [i] == '\t' || str[i] == '\v' || str[i] == '\n' \
			 || str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (get_long_result(result, count));
}
