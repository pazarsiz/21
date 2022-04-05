/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:49:03 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/03 12:50:51 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return ((void *)0);
	while (size)
		((unsigned char *)mem)[--size] = 0;
	return (mem);
}
