/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:09:51 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:54:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_H
# define FT_FIND_H

# include "../ft_lemin.h"

/*
** Algo
*/
int			ft_weight(t_env *env, t_hroom *start, int id, t_hroom *room);
void		ft_find_path(t_env *env, t_path *path);
void		ft_pathsend(t_path **path, char *datas);

/*
** Tools
*/
int			ft_hpipelen(t_hroom *hash);
t_hroom		*ft_find_room(t_env *env, char *datas);
t_hroom		*ft_find_good_pipe(t_hroom *room);
char		*ft_push_path(char **s1, char *s2);

#endif
