/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:14:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 16:58:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# define ROOMS env->rooms
# define END env->end

typedef struct		s_pipes
{
	char			*id;
	int				occuped;
	struct s_pipes	*prev;
	struct s_pipes	*next;
}					t_pipes;

typedef struct		s_rooms
{
	int				id;
	int				pos;
	int				weight;
	int				x;
	int				y;
	int				ant_id;
	long			ant;
	char			*name;
	struct s_pipes	*pipes;
	struct s_pipes	*pipes_prev;
	struct s_rooms	*prev;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_path
{
	int				moves;
	int				moves_max;
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_env
{
	long			ant;
	int				id;
	int				fd;
	int				f_soft;
	int				f_path;
	int				f_color;
	char			*map;
	char			*buff;
	struct s_path	*paths;
	struct s_rooms	*start;
	struct s_rooms	*end;
	struct s_rooms	*rooms;
}					t_env;

void				ft_extract(int ac, char **av, t_env **env);
void				ft_find(t_env *env);
void				ft_moves(t_env *env);

/*
** Tools
*/
void				ft_error(t_env *env, char *str);
long				ft_atoi_onum(char *str);
int					ft_pipeslen(t_pipes *pipes);
void				ft_colors(char **str, int color);

/*
** Clear
*/
void				ft_free_env(t_env **env, int i);
void				ft_clear_gnl(t_env *env);
void				ft_path_clear(t_path **begin_path);

/*
** Print
*/
void				ft_print_pipes(t_pipes *pipes);
void				ft_print_map(char *str);
void				ft_print_path(t_path *path);

/*
** Specific rooms
*/
t_rooms				*ft_find_start(t_rooms *rooms);
t_rooms				*ft_find_end(t_rooms *rooms);
t_rooms				*ft_find_room(t_rooms *rooms, char *datas);

#endif
