/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:35:06 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/01 15:35:16 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	d = (char *) dst;
	s = (const char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
