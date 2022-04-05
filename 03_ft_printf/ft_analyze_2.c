/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:24:14 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/24 13:56:11 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_argv	if_len_hh(char *finish_format, t_format_argv *specificator)
{
	if (*(finish_format + 1) == 'h')
	{
		specificator->length = len_hh;
		finish_format++;
	}
	else
		specificator->length = len_h;
	return (*specificator);
}

t_format_argv	if_len_ll(char *finish_format, t_format_argv *specificator)
{
	if (*(finish_format + 1) == 'l')
	{
		specificator->length = len_ll;
		finish_format++;
	}
	else
		specificator->length = len_l;
	return (*specificator);
}

char	*length(char *finish_format, t_format_argv *specificator)
{
	if (*finish_format == 'h')
		if_len_hh(finish_format, specificator);
	else if (*finish_format == 'l')
		if_len_ll(finish_format, specificator);
	else if (*finish_format == 'j')
		specificator->length = len_j;
	else if (*finish_format == 'z')
		specificator->length = len_z;
	else if (*finish_format == 't')
		specificator->length = len_t;
	else if (*finish_format == 'L')
		specificator->length = len_bigl;
	else
	{
		specificator->length = len_unknown;
		finish_format--;
	}
	return (finish_format + 1);
}

char	*type(char *finish_format, t_format_argv *specificator)
{
	if (*finish_format == 'c')
		specificator->type = typ_c;
	else if (*finish_format == 's')
		specificator->type = typ_s;
	else if (*finish_format == 'p')
		specificator->type = typ_p;
	else if (*finish_format == 'd')
		specificator->type = typ_d;
	else if (*finish_format == 'i')
		specificator->type = typ_i;
	else if (*finish_format == 'u')
		specificator->type = typ_u;
	else if (*finish_format == 'x')
		specificator->type = typ_x;
	else if (*finish_format == 'X')
		specificator->type = typ_X;
	else if (*finish_format == '%')
		specificator->type = typ_pr;
	else
	{
		specificator->type = typ_unknown;
		finish_format--;
	}
	return (finish_format + 1);
}

char	*analyze(const char *start_format, t_format_argv *specificator)
{
	char	*finish_format;

	specificator->flags = fl_unknown;
	specificator->length = len_unknown;
	specificator->precis = 0;
	specificator->wid = 0;
	specificator->type = typ_unknown;
	finish_format = flags(start_format + 1, specificator);
	finish_format = wid(finish_format, specificator);
	finish_format = precis(finish_format, specificator);
	finish_format = length(finish_format, specificator);
	finish_format = type(finish_format, specificator);
	return (finish_format);
}
