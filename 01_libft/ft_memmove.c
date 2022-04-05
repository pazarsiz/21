/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:13:10 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 12:13:40 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *) src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len --)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
