/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:38:22 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/04 11:42:57 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

char	*get_next_line(void)
{
	int		i;
	int		rd;
	char	ch;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(4);
	ft_bzero(buffer, 4);
	rd = read(0, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i] = ch;
		rd = read(0, &ch, 1);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/*
#include <stdio.h>
int	main(void)
{
		char **str = malloc(4);
		get_next_line(str);
		printf("%s\n", str[0]);
}
*/
