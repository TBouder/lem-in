/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:14:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/03 12:23:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# define ROOMS env->rooms
# define CMP ft_strcmp

typedef struct		s_pipes
{
	char			*id;
	long			ant;
	int				occuped;
	struct s_pipes	*prev;
	struct s_pipes	*next;
}					t_pipes;

typedef struct		s_rooms
{
	int				id;
	int				pos;
	char			*name;
	int				x;
	int				y;
	struct s_pipes	*pipes_next;
	struct s_pipes	*pipes_prev;
	struct s_rooms	*prev;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_env
{
	long			ant;
	int				id;
	int				fd;
	char			*map;
	char			*buff;
	struct s_rooms	*rooms;
}					t_env;

typedef struct		s_datas
{
	char			*name;
	char			*name_two;
	int				x;
	int				y;
	int				id;
	int				pos;
}					t_datas;

typedef struct		s_path
{
	int				moves;
	char			*path;
	struct s_path	*next;
}					t_path;

/*
** Tools
*/

void				ft_error(t_env *env, char *str);
long				ft_atoi_onum(char *str);
char				*ft_push_map(char **s1, char *s2);
int					ft_cmd(t_env *e, char **str);
int					ft_pipeslen(t_pipes *pipes);

/*
** Clear
*/

void				ft_free_all(t_env **env, int i);
void				ft_clear_gnl(t_env *env);

/*
** Extract
*/

int					ft_launch_extract(t_env *env, char **str, int part);
void				ft_extract_map(t_env *env, char **str);
void				ft_extract_pipes(t_datas *datas, char **str);
int					ft_put_pipes(t_datas datas, t_env *env);
int					ft_pipes(t_env *env);

/*
** Structs
*/

void				ft_roomsend(t_rooms **rooms, t_datas datas);
void				ft_pipesend(t_pipes **pipes, t_datas datas);
void				ft_pathsend(t_path **path, char *datas);

/*
** Verifs
*/

void				ft_verif_duplicates_rooms(t_env *env, t_datas datas);
int					ft_verif_duplicates_pipes(t_rooms pipes, t_datas datas);
void				ft_verif_launcher(t_env *env);

/*
** Print
*/

void				ft_print_pipes(t_pipes *pipes);
void				ft_putstrr(char *str);
void				ft_print_infos(t_env *env);
void				ft_print_path(t_path *path);


void				ft_algo(t_env *env);
char				*ft_push_path(char **s1, char *s2);
t_rooms				*ft_find_room(t_rooms *rooms, t_pipes *pipes);
t_rooms				*ft_find_start(t_rooms *rooms);
t_rooms				*ft_find_end(t_rooms *rooms);
t_rooms				*ft_find_room_s(t_rooms *rooms, char *datas);

void				ft_find_path(t_env *env, t_path *path);

#endif
