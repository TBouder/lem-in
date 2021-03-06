/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:14:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/26 15:18:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "libft/libft.h"
# include "ft_errors.h"
# include <fcntl.h>
# define END env->end
# define BUFF env->buff

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
	char			*coo_id;
	int				weight;
	ULL				ant;
	struct s_hpipe	*pipe;
	struct s_hroom	*next;
	struct s_hroom	*coo;
}					t_hroom;

typedef struct		s_flag
{
	int				f_soft;
	int				f_path;
	int				f_color;
	int				f_dist;
	int				f_info;
}					t_flag;

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
	int				path_len;

	int				get_ant;
	int				get_room;
	int				get_pipe;
	int				if_pipe;

	char			**map;
	char			*buff;

	t_flag			flag;
	t_path			*paths;
	t_hroom			**hash;
	t_hroom			**hash_coo;
	t_hroom			*r_start;
	t_hroom			*r_end;
}					t_env;

void				ft_extract(int ac, char **av, t_env **env);
void				ft_find(t_env *env);
void				ft_moves(t_env *env);

/*
** Tools (ft_tools & ft_gnl_num)
*/
ULL					ft_atoi_onum(char *str);
int					get_next_line_num(int const fd, char **line, int **x,
						int c);
int					ft_nbline_gnl(char *str, int x);
char				*ft_push_path(char **s1, char *s2);
void				ft_path_remove_if_error(t_path **begin_path, char *str);
int					ft_gnl_helper(int fd, t_list **lst, int j, int c);

/*
** Errors (ft_errors)
*/
void				ft_error(t_env *env, char *str);
void				ft_err_nopath(t_env *env, char *str);
void				ft_err_noenv(t_env *env, char *str);
void				ft_err_clr(char **err, t_env *env, char *str);
void				ft_err_nothing(char *str);

/*
** Clear (ft_free & ft_free_helper)
*/
void				ft_free_env(t_env **env, int i);
void				ft_free_hash(t_hroom **hash, int len);
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
void				ft_print_path(t_env *env);
void				ft_print_path_dist(t_env *env, int *dist);
void				ft_find_min_dist(t_env *env);

#endif
