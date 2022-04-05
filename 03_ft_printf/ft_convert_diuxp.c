/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_diuxp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:20:25 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/24 13:56:22 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_st(size_t num)
{
	char	*result;
	int		len_num;
	size_t	tmp;

	len_num = 1;
	tmp = num;
	tmp /= 10;
	while (tmp)
	{
		len_num++;
		tmp /= 10;
	}
	result = (char *)malloc(sizeof(char) * len_num + 1);
	if (!result)
		return (NULL);
	result[len_num] = '\0';
	result[--len_num] = num % 10 + '0';
	num /= 10;
	while (num)
	{
		result[--len_num] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}

char	*ft_convert(size_t num, const char *set, int base)
{
	char	*result;
	int		len_num;
	size_t	tmp;

	tmp = num;
	len_num = 1;
	tmp /= base;
	while (tmp)
	{
		len_num++;
		tmp /= base;
	}
	result = (char *)malloc(sizeof(char) * len_num + 1);
	if (!result)
		return (NULL);
	result[len_num] = '\0';
	result[--len_num] = set[num % base];
	num /= base;
	while (num)
	{
		result[--len_num] = set[num % base];
		num /= base;
	}
	return (result);
}

char	*ft_convert_p(size_t num, char *set, t_format_argv format_argv)
{
	char	*save;
	char	*prefix;
	char	*result;

	format_argv.type = typ_p;
	prefix = ft_strdup("0x");
	if (num == 0)
	{
		result = ft_strdup("0");
	}
	else
		result = ft_convert(num, set, 16);
	save = ft_strjoin(prefix, result);
	if (prefix)
		free(prefix);
	if (result)
		free(result);
	return (save);
}

char	*ft_convert_di(va_list argv)
{
	char	*save;
	int		result_num;

	result_num = va_arg(argv, int);
	save = ft_itoa(result_num);
	return (save);
}

char	*ft_convert_diuxp(va_list argv, t_format_argv format_argv)
{
	char	*save;
	size_t	result_num;

	save = NULL;
	if (format_argv.type == typ_p)
		result_num = va_arg(argv, unsigned long long int);
	else if (format_argv.type != typ_d && format_argv.type != typ_i)
		result_num = va_arg(argv, unsigned int);
	if (format_argv.type == typ_u)
		save = ft_itoa_st(result_num);
	else if (format_argv.type == typ_d || format_argv.type == typ_i)
		save = ft_convert_di(argv);
	if (format_argv.type == typ_x)
		save = ft_convert(result_num, "0123456789abcdef", 16);
	if (format_argv.type == typ_X)
		save = ft_convert(result_num, "0123456789ABCDEF", 16);
	if (format_argv.type == typ_p)
		save = ft_convert_p(result_num, "0123456789abcdef", format_argv);
	return (save);
}
