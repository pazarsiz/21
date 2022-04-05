/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:23:20 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 12:24:03 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;

	r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s1 || !r)
		return (NULL);
	r = ft_memcpy(r, s1, (ft_strlen(s1) + 1));
	return (r);
}
