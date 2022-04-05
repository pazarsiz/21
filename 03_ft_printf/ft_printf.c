/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:42:16 by wbungo            #+#    #+#             */
/*   Updated: 2022/04/04 13:21:00 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*malloc_sign(int x, char y)
{
	char	*dd;
	int		len;

	if (x == 0)
		len = 2;
	else
		len = x + 1;
	dd = (char *)malloc(len);
	dd[len - 1] = '\0';
	while (x >= 0)
		dd[x--] = y;
	return (dd);
}

int	output_c(t_format_argv specificator, va_list argv)
{
	int		sym_counter;
	char	*c_res;

	c_res = malloc_sign(specificator.wid, ' ');
	if (specificator.wid == 0)
		sym_counter = 1;
	else
		sym_counter = specificator.wid;
	c_res[sym_counter - 1] = va_arg(argv, int);
	write (1, c_res, sym_counter);
	free(c_res);
	return (sym_counter);
}

int	output_s(t_format_argv specificator, va_list argv)
{
	size_t	sym_counter;
	char	*s_res;
	char	*tmp;

	specificator.type = typ_s;
	tmp = va_arg(argv, char *);
	if (!tmp)
	{
		s_res = ft_strdup("(null)");
		sym_counter = 6;
	}
	else
	{
		s_res = ft_strdup(tmp);
		sym_counter = ft_strlen(tmp);
	}
	write (1, s_res, sym_counter);
	free(s_res);
	return (sym_counter);
}

int	output(t_format_argv specificator, va_list argv)
{
	if (specificator.wid == -1)
		specificator.wid = va_arg(argv, int);
	if (specificator.precis == -1)
		specificator.precis = va_arg(argv, int);
	if (specificator.type == typ_c)
		return (output_c(specificator, argv));
	else if (specificator.type == typ_d || specificator.type == typ_i)
		return (output_di(specificator, argv));
	else if (specificator.type == typ_u)
		return (output_u(specificator, argv));
	else if (specificator.type == typ_x || specificator.type == typ_X)
		return (output_x(specificator, argv));
	else if (specificator.type == typ_p)
		return (output_p(specificator, argv));
	else if (specificator.type == typ_s)
		return (output_s(specificator, argv));
	else if (specificator.type == typ_pr)
		return (output_pr(specificator));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_format_argv	specificator;	
	va_list			argv;
	int				total_n;

	total_n = 0;
	va_start(argv, format);
	while (*format)
	{
		if ((*format) != '%')
		{
			write (1, &(*format++), 1);
			total_n++;
		}
		else
		{
			format = analyze (format, &specificator);
			total_n += output (specificator, argv);
		}
	}
	va_end(argv);
	return (total_n);
}
