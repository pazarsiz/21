/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:28:43 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/24 13:57:35 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

enum e_flag {fl_unknown = - 1, fl_min, fl_plus, fl_spac, fl_hash, fl_zero};
enum e_len {len_unknown = - 1, len_h, len_hh, len_l, len_ll, len_j,	\
					len_z, len_t, len_bigl};
enum e_typ {typ_unknown = - 1, typ_c, typ_s, typ_p, typ_d, typ_i,	\
					typ_u, typ_x, typ_X, typ_pr};

typedef struct format_argv
{
	enum e_flag	flags;
	int			wid;
	int			precis;
	enum e_len	length;
	enum e_typ	type;
}	t_format_argv;

t_format_argv	if_len_hh(char *finish_format, t_format_argv *specificator);
t_format_argv	if_len_ll(char *finish_format, t_format_argv *specificator);

int				width(int x);
char			*flags(const char *finish_format, t_format_argv *specificator);
char			*wid(char *finish_format, t_format_argv *specificator);
char			*precis(char *finish_format, t_format_argv *specificator);
char			*length(char *finish_format, t_format_argv *specificator);
char			*type(char *finish_format, t_format_argv *specificator);
char			*analyze(const char *start_format, t_format_argv *specificator);

char			*ft_itoa_st(size_t num);
char			*ft_convert_di(va_list argv);
char			*ft_convert(size_t num, const char *set, int base);
char			*ft_convert_p(size_t num, char *set, t_format_argv format_argv);
char			*ft_convert_diuxp(va_list argv, t_format_argv format_argv);

char			*malloc_sign(int x, char y);

int				output_di(t_format_argv specificator, va_list argv);
int				output_u(t_format_argv specificator, va_list argv);
int				output_x(t_format_argv specificator, va_list argv);
int				output_p(t_format_argv specificator, va_list argv);
int				output_pr(t_format_argv specificator);
int				ft_printf(const char *format, ...);

#endif
