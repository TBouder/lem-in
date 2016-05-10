/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:09:15 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 19:24:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

void	ft_rev_datas(t_datas *datas)
{
	char	*s1;
	char	*s2;

	s1 = ft_strinit(datas->name);
	s2 = ft_strinit(datas->name_two);
	datas->name = NULL;
	datas->name_two = NULL;
	datas->name = ft_strinit(s2);
	datas->name_two = ft_strinit(s1);
	ft_strdel(&s1);
	ft_strdel(&s2);
}

int		ft_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isnumber(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_cmd(t_env *env, char **str)
{
	if (ft_strlen(str[0]) >= 2 && str[0][0] == '#' && str[0][1] == '#'
		&& str[0][2] == '#')
		return (0);
	if ((str[0][0] == '#' || str[0][0] != '#') && str[0][1] != '#')
		return (0);
	if (CMP("##start", env->buff) == 0 || CMP("##end", env->buff) == 0)
		return (0);
	return (1);
}

char	*ft_push_map(char **s1, char *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 2);
	ft_strcpy(str, *s1);
	ft_strcat(str, s2);
	ft_strcat(str, "\n");
	ft_strdel(s1);
	return (str);
}
