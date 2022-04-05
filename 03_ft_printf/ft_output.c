/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:33:16 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/24 13:56:37 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_di(t_format_argv specificator, va_list argv)
{
	int		sym_counter;
	char	*di_res;

	sym_counter = 0;
	di_res = ft_convert_diuxp(argv, specificator);
	write (1, di_res, ft_strlen(di_res));
	sym_counter += ft_strlen(di_res);
	free(di_res);
	return (sym_counter);
}

int	output_u(t_format_argv specificator, va_list argv)
{
	int		sym_counter;
	char	*u_res;

	sym_counter = 0;
	u_res = ft_convert_diuxp(argv, specificator);
	write (1, u_res, ft_strlen(u_res));
	sym_counter += ft_strlen(u_res);
	free(u_res);
	return (sym_counter);
}

int	output_x(t_format_argv specificator, va_list argv)
{
	int		sym_counter;
	char	*x_res;

	sym_counter = 0;
	x_res = ft_convert_diuxp(argv, specificator);
	write (1, x_res, ft_strlen(x_res));
	sym_counter += ft_strlen(x_res);
	free(x_res);
	return (sym_counter);
}

int	output_p(t_format_argv specificator, va_list argv)
{
	int		sym_counter;
	char	*p_res;

	sym_counter = 0;
	p_res = ft_convert_diuxp(argv, specificator);
	write (1, p_res, ft_strlen(p_res));
	sym_counter += ft_strlen(p_res);
	free(p_res);
	return (sym_counter);
}

int	output_pr(t_format_argv specificator)
{
	int		sym_counter;
	char	*pr_res;

	pr_res = malloc_sign(specificator.wid, ' ');
	if (specificator.wid == 0)
		sym_counter = 1;
	else
		sym_counter = specificator.wid;
	pr_res[sym_counter - 1] = '%';
	write (1, pr_res, sym_counter);
	free (pr_res);
	return (sym_counter);
}
