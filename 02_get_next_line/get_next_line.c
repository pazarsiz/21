/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_pre_final_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:50:54 by wbungo            #+#    #+#             */
/*   Updated: 2022/04/04 13:15:13 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_strcat(char **dst, char *src)
{
	char	*tmp;
	int		i;
	int		j;

	if (!dst || !src || !(*dst))
		return ;
	tmp = (char *)malloc(ft_strlen(*dst) + ft_strlen(src) + 1);
	i = 0;
	while ((*dst)[i])
	{
		tmp[i] = (*dst)[i];
		i++;
	}
	j = 0;
	while (src[j])
		tmp[i++] = src[j++];
	tmp[i] = '\0';
	free(*dst);
	free(src);
	*dst = tmp;
}

char	*get_tmp(char *tmp, char *s)
{
	gnl_strcat(&tmp, s);
	return (tmp);
}

void	buf_clean(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*s;
	char		*tmp;
	static char	buf[BUFFER_SIZE + 1];
	static int	buf_index;
	static int	sym_number;

	if (BUFFER_SIZE <= 0)
		return (0);
	while (get_line(&tmp, buf, sym_number, &buf_index))
		return (tmp);
	buf_clean(buf);
	sym_number = read(fd, buf, BUFFER_SIZE);
	while (sym_number > 0)
	{
		buf_index = 0;
		if (get_line(&s, &buf[buf_index], sym_number, &buf_index))
			return (get_tmp(tmp, s));
		gnl_strcat(&tmp, s);
		buf_clean(buf);
		sym_number = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_strlen(tmp) > 0)
		return (tmp);
	ft_strfree(&tmp);
	return (NULL);
}

int	main(int argc, char ** argv)
{
	int	fd;
	char	*line;

	if (argc == 1){
		printf("nothing to open");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
//	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
//		counter--;
//		printf("\ncounter_main: %d\n", counter);
		line = get_next_line(fd);
	}
	return (0);
}
