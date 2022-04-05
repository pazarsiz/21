/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:01:48 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/01 12:03:01 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;

	if (!*lst)
		return ;
	while (*lst)
	{
		a = (*lst)-> next;
		ft_lstdelone(*lst, (*del));
		*lst = a;
	}
	*lst = 0;
}
