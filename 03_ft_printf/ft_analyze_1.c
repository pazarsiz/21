/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:17:44 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/24 13:55:56 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flags(const char *finish_format, t_format_argv *specificator)
{
	if (*finish_format == '-')
		specificator->flags = fl_min;
	else if (*finish_format == '+')
		specificator->flags = fl_plus;
	else if (*finish_format == ' ')
		specificator->flags = fl_spac;
	else if (*finish_format == '#')
		specificator->flags = fl_hash;
	else if (*finish_format == '0')
		specificator->flags = fl_zero;
	else
	{
		specificator->flags = fl_unknown;
		finish_format--;
	}
	return ((char *)finish_format + 1);
}

int	width(int x)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

char	*wid(char *finish_format, t_format_argv *specificator)
{
	if (*finish_format >= '1' && *finish_format <= '9')
	{
		specificator->wid = ft_atoi (finish_format);
		return (finish_format + width(specificator->wid));
	}
	else if (*finish_format == '*')
	{
		specificator->wid = -1;
		finish_format++;
	}
	return (finish_format);
}

char	*precis(char *finish_format, t_format_argv *specificator)
{
	if (*finish_format == '.')
	{
		finish_format++;
		if (*finish_format == '*')
		{
			specificator->precis = -1;
			finish_format++;
		}
		else
		{
			specificator->precis = ft_atoi (finish_format);
			return (finish_format + width(specificator->precis));
		}
	}
	return (finish_format);
}
