/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:14:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 13:09:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# define END env->end
# define BUFF env->buff

# define ERR0 "File {9}error{0} : arg must be a file"
# define ERR17 "File {9}error{0} : malloc error"

# define ERR1 "Room {9}error{0} : multiple start room"
# define ERR2 "Room {9}error{0} : multiple end room"
# define ERR12 "Room {9}error{0} : same room"
# define ERR13 "Map {9}error{0} : same coo"

# define ERR6 "Map {9}error{0} : start or end room not well formated"
# define ERR7 "Map {9}error{0} : pipe not well formated"
# define ERR8 "Map {9}error{0} : room not well formated"
# define ERR16 "Map {9}error{0} : map not well formated"

# define ERR9 "Coo {9}error{0} : not a number"
# define ERR10 "Ant {9}error{0} : must be > 0 && < 4294967296"
# define ERR11 "Map {9}error{0} : empty line"
# define ERR5 "Room {9}error{0} : room name cannot start with 'L'"

# define ERR3 "Room {9}error{0} : no start room"
# define ERR4 "Room {9}error{0} : no end room"
# define ERR18 "Room {9}error{0} : no path start"
# define ERR19 "Room {9}error{0} : no access end"
# define ERR14 "Pipe {9}error{0} : no pipe"
# define ERR15 "Pipe {9}error{0} : no room for this pipe"

typedef struct		s_path
{
	int				moves;
	int				moves_max;
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_hpipe
{
	struct s_hroom	*room;
	struct s_hpipe	*next;
}					t_hpipe;

typedef struct		s_hroom
{
	char			*id;
	int				weight;
	ULL				ant;
	struct s_hpipe	*pipe;
	struct s_hroom	*next;
}					t_hroom;

typedef struct		s_env
{
	ULL				ant;
	int				id;
	int				fd;
	int				verif_fd;
	int				start;
	int				end;
	int				map_id;
	int				room_len;

	int				get_ant;
	int				get_room;
	int				get_pipe;
	int				if_pipe;

	int				f_soft;
	int				f_path;
	int				f_color;

	t_hroom			**hash;
	t_hroom			**hash_coo;
	t_path			*paths;
	char			**map;
	char			*null;
	char			*buff;

	t_hroom			*r_start;
	t_hroom			*r_end;
}					t_env;

void				ft_extract(int ac, char **av, t_env **env);
void				ft_find(t_env *env);
void				ft_moves(t_env *env);

/*
** Tools
*/
void				ft_error(t_env *env, char *str);
void				ft_err_clr(char **err, t_env *env, char *str);
ULL					ft_atoi_onum(char *str);
void				ft_colors(char **str, int color);
int					get_next_line_num(int const fd, char **line, int **x);
int					ft_nbline_gnl(char *str, int x);

/*
** Clear
*/
void				ft_free_env(t_env **env, int i);
void				ft_clear_gnl(t_env *env);

/*
** Errors
*/
void				ft_error(t_env *env, char *str);
void				ft_err_clr(char **err, t_env *env, char *str);
void				ft_err_noenv(t_env *env, char *str);
void				ft_err_nopath(t_env *env, char *str);

/*
** Print
*/
void				ft_print_map(t_env *env);
void				ft_print_map_pipes(t_env *env);
void				ft_print_map_weight(t_env *env);
void				ft_print_path(t_env *env);

#endif
