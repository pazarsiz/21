/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:58:35 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 11:59:23 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_zero(char *str)
{	
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_while(int n, int count, int znak, char *str)
{
	while (n != 0)
	{
		count--;
		str[count] = (char)((n % 10) * znak + '0');
		n = n / 10;
	}
	count--;
	if (znak < 0)
		str[count] = '-';
	return (str);
}

static char	*ft_count(int num, int count, int n, int znak)
{
	char	*str;

	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	if (n < 0)
		znak = -1;
	count = count + (n <= 0);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (str);
	if (n == 0)
		return (ft_zero(str));
	str[count] = '\0';
	return (ft_while(n, count, znak, str));
}

char	*ft_itoa(int n)
{
	int	num;
	int	znak;
	int	count;

	num = n;
	znak = 1;
	count = 0;
	return (ft_count(num, count, n, znak));
}
