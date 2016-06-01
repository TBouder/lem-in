/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_flg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:03:35 by tbouder           #+#    #+#             */
/*   Updated: 2016/06/01 14:36:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static void	ft_usage(char *str)
{
	ft_putstr_fd("usage : ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" [-scdpi] < [map]", 2);
	ft_putendl_fd("\tmap : one map well formated", 2);
	ft_putendl_fd("\t-s : Enable soft mode", 2);
	ft_putendl_fd("\t-c : Enable color mode", 2);
	ft_putendl_fd("\t-d : Swich to distance mode insteed of shortest mode", 2);
	ft_putendl_fd("\t-p : Display all the valid path used", 2);
	ft_putendl_fd("\t-i : Display some infos at the end", 2);
	exit(EXIT_FAILURE);
}

void		ft_set_flg(t_env *env, t_flg flg)
{
	env->flag.f_soft = flg.f_soft;
	env->flag.f_path = flg.f_path;
	env->flag.f_color = flg.f_color;
	env->flag.f_dist = flg.f_dist;
	env->flag.f_info = flg.f_info;
}

void		ft_init_flg(t_flg *flg)
{
	flg->f_soft = 0;
	flg->f_path = 0;
	flg->f_color = 0;
	flg->f_dist = 0;
	flg->f_info = 0;
	flg->nb = 0;
}

int			ft_extract_flg(char **str, t_flg *flg, int i, int j)
{
	while (str[i] && str[i][0] == '-' && ft_isalpha(str[i][1]))
	{
		j = 1;
		while (str[i][j] != '\0' && ft_isalpha(str[i][j]))
		{
			if (str[i][j] != 's' && str[i][j] != 'p' && str[i][j] != 'c'
				&& str[i][j] != 'd' && str[i][j] != 'i')
				ft_usage("./lem-in");
			str[i][j] == 's' ? flg->f_soft = 1 : 0;
			str[i][j] == 'p' ? flg->f_path = 1 : 0;
			str[i][j] == 'c' ? flg->f_color = 1 : 0;
			str[i][j] == 'd' ? flg->f_dist = 1 : 0;
			str[i][j] == 'i' ? flg->f_info = 1 : 0;
			j++;
		}
		i++;
	}
	return (i - 1);
}
