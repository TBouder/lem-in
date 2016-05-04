/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:51:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/04 11:49:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
While on est pas a room_end
	if il y a un seul pipe
		mettre la salle d'arrivee dans le chemin
		aller a la salle d'arrivee
	if il y a plusieurs pipes
		Enregistrer salle d'arrivee du premier pipe
		while il y a des pipes
			mettre la salle d'arrivee du premier pipe dans le chemin courant
			mettre les autres dans d'autres branches de la liste (non finie donc)
		aller a la salle d'arrivee du premier pipe
	if la salle est deja dans le chemin
		declarer le chemin invalide
		break

while il y a des chemins valides mais pas sur room_end
	aller a la premiere salle non finie et valide
	refaire l'operation de la premiere boucle while
*/
int		ft_cmpp(char *path, char *data_ref)
{
	char	*str;

	str = ft_strnew(500);
	str = ft_strstr(path, data_ref);
	if (str == NULL)
	{
		ft_strdel(&str);
		return (0);
	}
	return (1);
}
//---//

t_rooms	*ft_error_pipe(t_path *path)
{
	path->path = ft_push_path(&path->path, "ERROR");
	return (NULL);
}

t_rooms	*ft_one_pipe(t_env *env, t_path *path, t_pipes *pipe)
{
	char	*r;
	char	**str;

	path->path = ft_push_path(&path->path, ft_find_room(env->rooms, pipe)->name);
	path->moves += 1;
	str = ft_strsplit(path->path, ' ');
	r = ft_strinit(str[ft_dbstrlen(str) - 1]);
	ft_dbstrdel(str);

	return (ft_find_room_s(env->rooms, r));
}

t_rooms	*ft_mult_pipe(t_env *env, t_path *path, t_pipes *pipes)
{
	t_pipes	*p;
	char	*temp_path;
	// char	*s;

	p = NULL;
	// pipes = pipes->next;
	while (pipes)
	{
		if (!ft_strstr(path->path, pipes->id) && path->moves_max < path->moves + 1)
		{
			temp_path = ft_strinit(path->path);
			temp_path = ft_push_path(&temp_path, ft_find_room(env->rooms, pipes)->name);
			ft_pathsend(&path, temp_path);
			!p ? p = pipes : 0;
			ft_strdel(&temp_path);
		}
		pipes = pipes->next;
	}
	if (p)
	{
		return (ft_one_pipe(env, path, p));
	}
	else
		return (ft_error_pipe(path));
}

void	ft_find_path(t_env *env, t_path *path)
{
	t_rooms *rooms;
	t_pipes *pipes;
	char 	*end;

	rooms = ft_find_room_s(env->rooms, path->path);
	end = ft_find_end(env->rooms)->name;
	// ft_printf("Start : %s\n", path->path);
	while (rooms && !ft_strstr(path->path, end))
	{
		pipes = rooms->pipes_next;
		if (ft_pipeslen(pipes) == 1)
		{
			ft_printf("{b}%d{0} vs {c}%d{0}\n", path->moves_max, path->moves);
			rooms = ft_one_pipe(env, path, rooms->pipes_next);
			// ft_printf("One : {b}%s{0}\n", path->path);
		}
		else if (ft_pipeslen(pipes) > 1)
		{
			// ft_printf("{c}%d{0} vs {b}%d{0}\n", path->moves_max < path->moves + 1);
			rooms = ft_mult_pipe(env, path, rooms->pipes_next);

			// ft_printf("Two : {c}%s{0}\n", path->path);
		}
	}
}
