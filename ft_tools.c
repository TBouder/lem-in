/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:51:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/09 22:00:45 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_error(t_env *env, char *str)
{
	ft_printf("%s\n", str);
	ft_clear_gnl(env);
	if (!env)
		ft_free_env(&env, 0);
	exit(EXIT_FAILURE);
}

long	ft_atoi_onum(char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (ft_strlen(str) == 0 || (*str < 32 && !ft_isspace(*str)))
		return (-1);
	while (*str <= 32)
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isnumber(*str))
		result = (result + *str++ - '0') * 10;
	if ((!(ft_isnumber(*str)) && *str != '\0') || (result / 10 * sign == 0))
		return (-1);
	return (result / 10 * sign);
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

int		ft_cmd(t_env *e, char **str)
{
	if (ft_strlen(str[0]) >= 2 && str[0][0] == '#' && str[0][1] == '#'
		&& str[0][2] == '#')
		return (0);
	if ((str[0][0] == '#' || str[0][0] != '#') && str[0][1] != '#')
		return (0);
	if (CMP("##start", e->buff) == 0 || CMP("##end", e->buff) == 0)
		return (0);
	return (1);
}

int		ft_pipeslen(t_pipes *pipes)
{
	t_pipes	*tmp;
	int		i;

	i = 0;
	tmp = pipes;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
