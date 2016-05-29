/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/29 12:34:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static void	ft_check_errors(t_env *env)
{
	env->start == 0 ? ft_err_nopath(env, ERR13) : 0;
	env->end == 0 ? ft_err_nopath(env, ERR14) : 0;
	env->r_start->pipe == NULL ? ft_err_nopath(env, ERR15) : 0;
	env->r_end->pipe == NULL ? ft_err_nopath(env, ERR16) : 0;
	env->if_pipe != 1 ? ft_err_nopath(env, ERR17) : 0;
	env->verif_fd == -1 ? ft_err_nopath(env, ERR00) : 0;
}

static int	ft_extended_get_map(t_env *env, int *lines)
{
	if (BUFF[0] == '#')
		ft_get_diaiz(env, lines);
	else if (BUFF[0] == '\0' && env->if_pipe == 1)
		return (1);
	else if (BUFF[0] == '\0')
	{
		free(lines);
		ft_err_nopath(env, ERR11);
	}
	else if (env->get_ant == 0 && ft_isstrnum(BUFF))
		ft_get_ant(env);
	else if ((env->get_ant == 0 && !ft_isstrnum(BUFF)) || env->ant < 1)
		ft_err_noenv(env, ERR10);
	else if (ft_strchr(BUFF, '-') && (env->get_pipe = -1) && env->get_room == 1)
	{
		if (ft_get_pipe(env, 0) == 1)
			return (1);
	}
	else if (env->get_pipe == 0)
		ft_get_room(env, lines);
	else if (env->get_pipe == 1)
		return (1);
	else
		ft_err_nopath(env, ERR08);
	return (0);
}

static int	ft_zero(t_env **env, t_flg *flg)
{
	(!(*env = (t_env *)malloc(sizeof(t_env)))) ? exit(1) : 0;
	ft_init_env(*env);
	ft_set_flg(*env, *flg);
	ft_get_map(*env);
	return (1);
}

void		ft_get_map(t_env *env)
{
	int		*lines;

	lines = ft_nbrnew(2);
	while ((env->verif_fd = get_next_line_num(env->fd, &BUFF, &lines)) == 1)
	{
		ft_malloc_env(env, lines);
		env->room_len = lines[0] - 1;
		if (ft_extended_get_map(env, lines) == 1)
		{
			ft_clear_gnl(env);
			break ;
		}
		ft_strdel(&BUFF);
	}
	free(lines);
	ft_check_errors(env);
}

void		ft_extract(int ac, char **av, t_env **env)
{
	t_flg	flg;
	int		i;

	i = 0;
	ft_init_flg(&flg);
	i += ft_extract_flg(av, &flg, 1, 0);
	flg.nb = i;
	if (ac - i == 1)
		ft_zero(env, &flg);
	else if (ac - i >= 2)
		ft_more(ac, av, env, &flg);
	else
		ft_putchar('\n');
}
