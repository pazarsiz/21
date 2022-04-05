/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:43:43 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/03 12:45:12 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int		i;

	if (!n)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	i = numlen(n);
	num = (char *)ft_memalloc(i + 1);
	if (!(num))
		return (0);
	if (n < 0)
		num[0] = '-';
	num[i--] = 0;
	if (!n)
		num[i] = '0';
	while (n)
	{
		if (n < 0)
			num[i--] = (n % 10) * -1 + 48;
		else
			num[i--] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}
