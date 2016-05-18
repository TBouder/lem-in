/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:34:10 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 15:59:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_H
# define FT_FIND_H

# include "../ft_lemin.h"

int		ft_weight(t_rooms *origin, t_rooms *rooms, int id);
void	ft_purge_rooms(t_rooms **begin_rooms, t_rooms **origin);
void	ft_algo(t_env *env, t_path *path);
void	ft_find_path(t_env *env, t_path *path);

char	*ft_push_path(char **s1, char *s2);
void 	ft_path_remove_if_error(t_path **begin_path, char *str);
void	ft_display_paths(t_path *origin, int color);

void	ft_pathsend(t_path **path, char *datas);

#endif
