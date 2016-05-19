/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:51:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 16:26:05 by tbouder          ###   ########.fr       */
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

ULL		ft_atoi_onum(char *str)
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
		if (result > 4294967295)
			return (0);
	}
	if ((!(ft_isnumber(*str)) && *str != '\0') || (result == 0))
		return (0);
	return (result);
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

void	ft_clear_gnl(t_env *env)
{
	if (env && env->map)
	{
		ft_strdel(&env->buff);
		while (get_next_line(env->fd, &env->buff) == 1)
			ft_strdel(&env->buff);
		ft_strdel(&env->buff);
	}
}

void	ft_colors(char **str, int color)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (color && ((i + 1) % 8) == 0)
			ft_printf("{27}%s{0} ", str[i]);
		else if (color && ((i + 1) % 7) == 0)
			ft_printf("{39}%s{0} ", str[i]);
		else if (color && ((i + 1) % 6) == 0)
			ft_printf("{51}%s{0} ", str[i]);
		else if (color && ((i + 1) % 5) == 0)
			ft_printf("{75}%s{0} ", str[i]);
		else if (color && ((i + 1) % 4) == 0)
			ft_printf("{81}%s{0} ", str[i]);
		else if (color && ((i + 1) % 3) == 0)
			ft_printf("{105}%s{0} ", str[i]);
		else if (color && ((i + 1) % 2) == 0)
			ft_printf("{123}%s{0} ", str[i]);
		else if (color && ((i + 1) % 1) == 0)
			ft_printf("{147}%s{0} ", str[i]);
		else
			ft_printf("%s ", str[i]);
		i++;
	}
}
