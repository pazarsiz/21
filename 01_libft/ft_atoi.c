/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:39:34 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 11:53:50 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	process_the_number(const char *str, int z)
{
	int	num;
	int	old_num;
	int	counter;

	num = 0;
	counter = 0;
	while (*str >= '0' && *str <= '9')
	{
		old_num = num;
		num = num * 10;
		num = num + (*str - 48) * z;
		if ((num >= 0 && old_num < 0) || (num < 0 && old_num >= 0))
		{
			counter += z;
			if (counter == 8 || counter == -9)
				return (0 - (counter > 0));
		}
		str++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	z;

	z = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			z = -1;
		str++;
	}
	return (process_the_number(str, z));
}
