/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/04 18:33:16 by tbouder          ###   ########.fr       */
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


int		ft_dead_end(t_rooms *rooms)
{
	if (rooms->pos == 0 && ft_pipeslen(rooms->pipes_next) == 1)
		return (1);
	return (0);
}

int		ft_useless_pipe(t_pipes *pipes, char *data)
{
	if (ft_strequ(pipes->id, data))
		return (1);
	return (0);
}

// void 	ft_remove_empty_pipes(t_rooms **begin_rooms, char *data)
// {
// 	ft_putendl(data); // AFFICHE LES SALLES DELETE
// 	t_rooms	*rooms;
// 	t_pipes	*tmp;
// 	t_pipes	*pipes;
//
// 	rooms = *begin_rooms;
// 	while (rooms)
// 	{
// 		pipes = rooms->pipes_next;
// 		while (pipes && ft_useless_pipe(pipes->next, data))
// 		{
// 			tmp = pipes;
// 			pipes = (pipes)->next;
// 			free(tmp);
// 		}
// 		while (pipes && pipes->next)
// 		{
// 			if (ft_useless_pipe(pipes->next, data))
// 			{
// 				ft_putstr("\t");ft_putendl(pipes->next->id); // AFFICHE LES SALLES DELETE
// 				tmp = pipes->next;
// 				pipes->next = tmp->next;
// 				free(tmp);
// 			}
// 			pipes = pipes->next;
// 		}
// 		rooms = rooms->next;
// 	}
// }
//

void 	ft_remove_empty_pipes(t_rooms *rooms, t_pipes *pipe)
{
	t_pipes	*tmp;
	t_pipes	*p;

	while (ft_strequ((pipe)->id, rooms->name))
	{
		tmp = pipe;
		pipe = (pipe)->next;
		free(tmp);
	}
	p = pipe;
	while (p && p->next)
	{
		// ft_putstr(p->id); ft_putstr(" : "); ft_putendl(rooms->name);
		// ft_nbrendl(ft_strequ(p->id, rooms->name));
		if (ft_strequ(p->id, rooms->name))
		{
			ft_putendl(tmp->id);
			// tmp = p->next;
			// p->next = tmp->next;
			// free(tmp);
		}
		if (p->next)
			p = p->next;
	}
}

void 	ft_rooms_remove_if(t_rooms **begin_rooms)
{
	t_rooms	*tmp;
	t_rooms	*rooms;

	while (*begin_rooms && ft_dead_end(*begin_rooms))
	{
		tmp = *begin_rooms;
		*begin_rooms = (*begin_rooms)->next;
		free(tmp);
	}
	rooms = *begin_rooms;
	while (rooms && rooms->next)
	{
		if (ft_dead_end(rooms->next))
		{
			//Il faut trouver la salle vers laquelle pointe rooms->next->name
			//rooms->next->pipes_next->id POINTE VERS rooms->next->name
			t_pipes *pipes = ft_find_room_s(*begin_rooms, rooms->next->pipes_next->id)->pipes_next;
			ft_printf("Salle sans issus : %s | Acces par : %s\n", rooms->next->name, rooms->next->pipes_next->id);
			while (pipes)
			{
				if (ft_strequ(rooms->next->name, pipes->id))
				{

				}
					ft_putstr("MATCH : ");
				ft_putendl(pipes->id);
				pipes = pipes->next;
			}
			ft_printf("------------------------\n");
			tmp = rooms->next;
			rooms->next = tmp->next;
			free(tmp);
		}
		if (rooms->next)
			rooms = rooms->next;
	}
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

	ft_rooms_remove_if(&env->rooms);
	// ft_rooms_remove_if(&env->rooms);
	// ft_rooms_remove_if(&env->rooms);
	// ft_rooms_remove_if(&env->rooms);
	// ft_rooms_remove_if(&env->rooms);
	// ft_rooms_remove_if(&env->rooms);


	// ft_progress(env->rooms, ft_find_start(env->rooms), ft_find_end(env->rooms), -1);
	// ft_print_infos(env);

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
