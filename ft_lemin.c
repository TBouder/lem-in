/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/04 12:59:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"
#define TEST (env->buff[0] == '#' || env->buff[0] != '#') && env->buff[1] != '#'

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
*/

void	ft_apply_progress(t_rooms *rooms, t_rooms *origin)
{
	t_pipes	*pipes;
	t_rooms	*n_room;

	pipes = rooms->pipes_next;
	while (pipes)
	{
		n_room = ft_find_room_s(origin, pipes->id);
		if (n_room->progress == -1)
			n_room->progress = rooms->progress + 1;
		pipes = pipes->next;
	}
}

int		ft_test(t_rooms *origin, t_rooms *start, t_rooms *end, int id)
{
	t_rooms	*tmp;
	t_pipes	*pipes;

	tmp = start;
	if (end->progress != -1)
		return (2);
	if (tmp->progress != id)
		return (1);
	if (tmp->progress == -1)
		tmp->progress = id + 1;
	ft_apply_progress(tmp, origin);
	while (tmp)
	{
		pipes = tmp->pipes_next;
		while (pipes)
		{
			// ft_putstr(tmp->name); ft_putstr(" : "); ft_putstr(pipes->id); ft_putstr(" | "); ft_nbrendl(tmp->progress);
			// tmp = ft_find_room_s(origin, origin->pipes_next->id);
			ft_printf("IN %s FOR %s ID %d\n",tmp->name, pipes->id, tmp->progress);
			// pipes = tmp->pipes_next->next;
			ft_test(origin, tmp, end, id + 1);
			pipes = pipes->next;
		}

		pipes = tmp->pipes_next;
		while (pipes)
		{
			ft_test(origin, ft_find_room_s(origin, pipes->id), end, id + 1);
			pipes = pipes->next;
		}
		tmp = tmp->next;

	}
	// ft_test(origin, origin, end, id + 1);
	// tmp = start;
	// ft_test(origin, tmp, end, id + 1);
	// tmp = start;
	// ft_test(origin, tmp, end, id + 1);


	return (0);
}

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

	ft_test(env->rooms, ft_find_start(env->rooms), ft_find_end(env->rooms), -1);

	ft_print_infos(env);

// Faire une fonction pour ajouter les poirds(progess) sur les maps, depuis start
	// ft_algo(env);


	ft_clear_gnl(env);
	ft_free_all(&env, 1);
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
