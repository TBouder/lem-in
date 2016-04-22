/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:14:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/22 16:00:57 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEMIN_H
# define FT_LEMIN_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct		s_pipes
{
	long			ant;
	int				occuped;
	struct s_pipes	*prev;
	struct s_pipes	*next;
}					t_pipes;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	struct s_pipes	*rooms;
	struct s_rooms	*prev;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_env
{
	long			ant;
	struct s_rooms	*rooms;
}					t_env;

void	ft_error(char *str);
long	ft_atoi_onum(const char *str);

void	ft_open_stdin(t_env *env);
void	ft_open_one(t_env *env, char **av);
void	ft_open_mult(t_env *env, char *map);


#endif
