/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:35:09 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 20:51:59 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= len)
		len = ft_strlen(s);
	if (ft_strlen(s) <= (size_t) start)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(*s) * (len + 1));
	if (!new)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
