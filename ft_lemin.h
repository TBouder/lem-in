/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:14:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/24 18:26:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# define ROOMS env->rooms

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

void	ft_error(char *str);
long	ft_atoi_onum(const char *str);
int		ft_dbtablelen(char **str);

void	ft_open_stdin(t_env *env);
void	ft_open_file(t_env *env, char *map);

void	ft_extract_map(t_env *env, int fd, char *buff, char **str);

void	ft_roomsend(t_rooms **rooms, t_datas datas);
void	ft_pipesend(t_pipes **pipes, t_datas datas);

#endif
