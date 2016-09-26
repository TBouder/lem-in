/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:14:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/08 15:10:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strtrim_char() function returns the string s without the custom char
** c at the beginning and at the end.
*/

#include "../libft.h"
#include <stdlib.h>

static int		count_spaces_st(char const *s, char c)
{
	int		i;
	int		custom_char;

	i = 0;
	custom_char = 0;
	while (s[i] == c)
	{
		i++;
		custom_char++;
	}
	return (custom_char);
}

static int		count_spaces_nd(char const *s, char c)
{
	int		j;
	int		custom_char;

	j = 1;
	custom_char = 0;
	while (s[ft_strlen(s) - j] == c)
	{
		j++;
		custom_char++;
	}
	return (custom_char);
}

char			*ft_strtrim_char(char const *s, char c)
{
	char	*str;
	int		custom_char;

	if (s == NULL)
		return (NULL);
	custom_char = count_spaces_st(s, c) + count_spaces_nd(s, c);
	str = ft_strnew(ft_strlen(s) - custom_char);
	str = ft_strsub(s, count_spaces_st(s, c), ft_strlen(s)
		- count_spaces_nd(s, c));
	str[ft_strlen(s) - custom_char] = '\0';
	return (str);
}
