/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/04 23:53:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"
#define TEST (env->buff[0] == '#' || env->buff[0] != '#') && env->buff[1] != '#'

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
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


//****************************************************************************//
int		ft_pipeslen_w(t_rooms *origin, t_pipes *pipes, int id)
{
	t_pipes	*tmp;
	int		prev_id;
	int		i;

	id = 0;
	i = 0;
	tmp = pipes;
	while (tmp)
	{
		prev_id = ft_find_room_s(origin, tmp->id)->progress;
		if (prev_id == -1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_rooms	*ft_pipesgo_w(t_rooms *origin, t_pipes *pipes)
{
	t_pipes	*tmp;
	int		prev_id;

	tmp = pipes;
	while (tmp)
	{
		prev_id = ft_find_room_s(origin, tmp->id)->progress;
		if (prev_id == -1)
			return (ft_find_room_s(origin, tmp->id));
		tmp = tmp->next;
	}
	return (NULL);
}

static void	ft_weight(t_rooms *origin, t_rooms *rooms, int id)
{
	if (ft_pipeslen_w(origin, rooms->pipes_next, id) == 1)
	{
		rooms->progress = id;
		ft_weight(origin, ft_pipesgo_w(origin, rooms->pipes_next), id + 1);
	}
	else
	{
		ft_putendl(rooms->name);
		while (rooms->pipes_next)
		{
			ft_putendl(rooms->pipes_next->id);
			rooms->pipes_next = rooms->pipes_next->next;
		}
	}
}
//****************************************************************************//

static int	ft_zero(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	env->fd = 0;
	env->ant = 0;
	env->map = NULL;
	env->id = 0;
	ROOMS = NULL;
	ft_open(env);
	// ft_putstrr(env->map);
	// ft_print_infos(env);

	// ft_purge_useless_rooms(&env->rooms, &env->rooms);
	ft_weight(env->rooms, env->rooms, 0);
	// ft_progress(env->rooms, ft_find_start(env->rooms), ft_find_end(env->rooms), -1);
	ft_print_infos(env);
	// ft_algo(env);

	ft_clear_gnl(env);
	// ft_free_all(&env, 1);
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
		if ((env->fd = open(av[i], O_RDONLY)) == -1)
			ft_error(env, "Opening {r}error{0} : wrong map");
		env->ant = 0;
		env->map = NULL;
		env->id = 0;
		ROOMS = NULL;
		ft_open(env);
		ft_putstr(env->map);
		// ft_print_infos(env);
		ft_algo(env);
		ft_clear_gnl(env);
		ft_free_all(&env, 1);
	}
	return (1);
}

int			main(int ac, char **av)
{
	if (ac == 1)
		ft_zero();
	else if (ac >= 2)
		ft_more(ac, av);
	else
		ft_putchar('\n');
	return (0);
}
