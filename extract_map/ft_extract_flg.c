/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_flg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:03:35 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/29 16:03:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

void	ft_set_flg(t_env *env, t_flg flg)
{
	env->flag.f_soft = flg.f_soft;
	env->flag.f_path = flg.f_path;
	env->flag.f_color = flg.f_color;
	env->flag.f_dist = flg.f_dist;
}

void	ft_init_flg(t_flg *flg)
{
	flg->f_soft = 0;
	flg->f_path = 0;
	flg->f_color = 0;
	flg->f_dist = 0;
	flg->nb = 0;
}

int		ft_extract_flg(char **str, t_flg *flg, int i, int j)
{
	while (str[i] && str[i][0] == '-' && ft_isalpha(str[i][1]))
	{
		j = 1;
		while (str[i][j] != '\0' && ft_isalpha(str[i][j]))
		{
			str[i][j] == 's' ? flg->f_soft = 1 : 0;
			str[i][j] == 'p' ? flg->f_path = 1 : 0;
			str[i][j] == 'c' ? flg->f_color = 1 : 0;
			str[i][j] == 'd' ? flg->f_dist = 1 : 0;
			j++;
		}
		i++;
	}
	return (i - 1);
}
