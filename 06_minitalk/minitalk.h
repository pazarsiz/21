/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:15:53 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/03 12:18:03 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdbool.h>

# define BUFFSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_stack
{
	char		message[BUFFSIZE];
	int			bit;
	int			byte;
	bool		received;
	bool		buff_overflow;
}				t_stack;

t_stack			g_message = {{0}, 64, 0, FALSE, FALSE};

void			error(char *str_error);

#endif
