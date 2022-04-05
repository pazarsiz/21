/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:45:12 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/09 11:44:36 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_strfree(char **t);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	gnl_strcat(char **dst, char *src);

int		get_line(char **t, const char *s, const int size, int *index);
char	*get_tmp(char *tmp, char *s);

char	*get_next_line(int fd);

#endif
