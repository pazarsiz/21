/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:31:28 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 12:31:56 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
