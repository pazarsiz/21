/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:41:05 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 16:20:15 by wbungo           ###   ########.fr       */
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
