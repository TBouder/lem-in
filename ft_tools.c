/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:51:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 16:42:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

ULL			ft_atoi_onum(char *str)
{
	ULL		result;

	result = 0;
	if (ft_strlen(str) == 0 || *str <= 32 || *str == '-' || *str == '+')
		return (0);
	while (ft_isnumber(*str))
	{
		result = (result + *str++ - '0');
		if (ft_isnumber(*str))
			result *= 10;
		if (result > 2147483647)
			return (0);
	}
	if ((!(ft_isnumber(*str)) && *str != '\0') || (result == 0))
		return (0);
	return (result);
}

void		ft_clear_gnl(t_env *env)
{
	if (env && env->map)
	{
		ft_strdel(&env->buff);
		while (get_next_line_num(env->fd, &env->buff, NULL) == 1)
			ft_strdel(&env->buff);
		ft_strdel(&env->buff);
	}
}

int			ft_nbline_gnl(char *str, int x)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (str[i])
	{
		if (str[i] == '-' && x == 1)
			break ;
		if (str[i] == '\n')
			r++;
		i++;
	}
	return (r);
}
