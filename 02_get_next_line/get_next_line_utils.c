/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_pre_final_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:50:54 by wbungo            #+#    #+#             */
/*   Updated: 2021/12/09 11:44:39 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s || s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_strfree(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

int	ft_flag(const char *s, char **t, int i, int *index)
{
	int	flag;

	flag = 0;
	if (s[*index] == '\n')
	{
		(*t)[i] = '\n';
		(*index)++;
		i++;
		flag = 1;
	}
	(*t)[i] = '\0';
	return (flag);
}

int	get_line(char **t, const char *s, const int size, int *index)
{
	int	i;

	i = 0;
	(*t) = NULL;
	if (size != 0)
		(*t) = ft_strnew(size - *index + 1);
	else
	{
		(*t) = ft_strnew(0);
		return (0);
	}
	while (s[*index] != '\n' && *index < size)
		(*t)[i++] = s[(*index)++];
	return (ft_flag(s, t, i, index));
}
