/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:20:46 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/03 12:22:55 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long int	num;
	int					sign;

	while (ft_iswhitespaces(*str))
		str++;
	num = 0;
	sign = check_sign(str);
	if (sign == -1 || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - 48);
	if (num >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (num > 9223372036854775807 && sign == -1)
		return (0);
	return ((int)num * sign);
}
