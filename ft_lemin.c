/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 11:58:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"
#define TEST (env->buff[0] == '#' || env->buff[0] != '#') && env->buff[1] != '#'

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
** - Possibility to use -s for soft mode (for the map extract) (Allows same pipe)
*/

static void	ft_init_buff(t_env *env, char **str)
{
	if (!env->map)
	{
		*str = ft_strnew(ft_strlen(env->buff));
		env->map = ft_push_map(str, env->buff);
	}
	else
		env->map = ft_push_map(&env->map, env->buff);
	ft_strdel(str);
}

static void	ft_open(t_env *env)
{
	char	*str;
	int		fd;

	while (env->ant == 0 && (fd = get_next_line(env->fd, &env->buff)) == 1)
	{
		TEST ? ft_init_buff(env, &str) : 0;
		if (env->buff[0] != '#' && !ft_isdigit(env->buff[0]))
			ft_error(env, "Ant {r}error{0} : must be number > to 0");
		else if (env->buff[0] != '#')
		{
			env->ant = ft_atoi_onum(env->buff);
			if (env->ant == -1)
				ft_error(env, "Ant {r}error{0} : must be number > to 0");
		}
		ft_strdel(&env->buff);
	}
	if (fd == -1)
	{
		ft_printf("File {r}error{0} : arg must be a file\n");
		exit(EXIT_FAILURE);
	}
	ft_strdel(&env->buff);
	ft_extract_map(env, NULL);
}

static int	ft_zero(int	i)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	ft_set_env(env);
	env->fd = 0;
	env->mode = i;
	ft_open(env);
	ft_weight(ROOMS, ft_find_start(ROOMS), 0);
	ft_purge_rooms(&ROOMS, &ROOMS);
	if (ft_find_end(ROOMS)->weight == -1)
		ft_error(env, "Pipe {r}error{0} : no access to end room");
	ft_putstrr(env->map);

//PATH
	ft_algo(env);
	// ft_print_infos(env);
	ft_putstr(env->path);

//MOVE
	ft_putchar('\n');
	ft_mv_ants(env);


	ft_clear_gnl(env);
	ft_free_env(&env, 1);
	return (1);
}

static int	ft_more(int ac, char **av)
{
	t_env	*env;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			return (0);
		ft_set_env(env);
		if ((env->fd = open(av[i], O_RDONLY)) == -1)
			ft_error(env, "Opening {r}error{0} : wrong map");
		ft_open(env);
		ft_putstr(env->map);
		ft_print_infos(env);
		// ft_algo(env);
		ft_clear_gnl(env);
		ft_free_env(&env, 1);
	}
	return (1);
}

int			main(int ac, char **av)
{
	if (ac == 1)
		ft_zero(0);
	else if (ac >= 2)
	{
		if (ft_strequ(av[1], "-s"))
			ft_zero(1);
		else
			ft_more(ac, av);
	}
	else
		ft_putchar('\n');
	return (0);
}
