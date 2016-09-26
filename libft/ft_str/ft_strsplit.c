/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:06:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 15:17:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strsplit() function allocates and returns a table of strings (clean
** they end with \0) where each part results of the split of s according to c.
*/

#include "../libft.h"
#include <stdlib.h>

static int		count_w(char const *s, char *c)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	j = 0;
	word = 0;
	if (ft_strstr(s, c) == NULL)
		return (1);
	while (s[i])
	{
		while (s[i] != c[0] && s[i])
		{
			j++;
			i++;
		}
		if (j != 0 && ((s[i] == c[0]) || s[i] == '\0'))
		{
			j = 0;
			word++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (word);
}

static int		count_l(char const *s, char c)
{
	int		letter;
	int		i;

	letter = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		letter++;
	}
	return (letter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		n_words;
	int		i;
	char	n_c[1];

	i = 0;
	n_c[0] = c;
	if (s == NULL)
		return (NULL);
	n_words = count_w(s, n_c);
	if (!(str = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return (NULL);
	if (s[0] == '\0')
		str[i] = ft_strsub(s, 0, count_l(s, c));
	while (n_words-- && s[0] != '\0')
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub(s, 0, count_l(s, c));
		s = s + count_l(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
