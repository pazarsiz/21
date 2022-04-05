/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:18:35 by wbungo            #+#    #+#             */
/*   Updated: 2021/11/02 13:33:14 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_num(const char *str, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*str)
	{
		if (*str != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*str == c)
			check = 0;
		str++;
	}
	return (i);
}

static char	*word_fill(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_spl(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && check < 0)
			check = i;
		else if ((s[i] == c || i == ft_strlen(s)) && check >= 0)
		{
			split[j++] = word_fill(s, check, i);
			check = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((sizeof(char *)) * (words_num(s, c) + 1));
	if (!split)
		return (NULL);
	return (ft_spl(s, c, split));
}
	/*
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && check < 0)
			check = i;
		else if ((s[i] == c || i == ft_strlen(s)) && check >= 0)
		{
			split[j++] = word_fill(s, check, i);
			check = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
*/
