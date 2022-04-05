/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:27:21 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 12:28:01 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	d = ft_strlen(dst);
	s = 0;
	while (src[s] != '\0' && (d + 1) < size)
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (d + ft_strlen(&src[s]));
}
