/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:07:16 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 22:10:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXTRACT_H
# define FT_EXTRACT_H

# include "../ft_lemin.h"
# define CMP ft_strcmp

typedef struct	s_datas
{
	char		*name;
	char		*name_two;
	int			x;
	int			y;
	int			id;
	int			pos;
}				t_datas;

void			ft_extract_map(t_env *env, char **str);
int				ft_extract_pipes(t_env *env, char **str);
int				ft_extract_part(t_env *env, char **str, int part);
int				ft_put_pipes(t_datas datas, t_env *env);

void			ft_rev_datas(t_datas *datas);
int				ft_num(char *str);
int				ft_cmd(t_env *env, char **str);
char			*ft_push_map(char **s1, char *s2);

void			ft_verif_duplicates_rooms(t_env *env, t_datas datas);
int				ft_dup_pipes(t_rooms pipes, t_datas datas);
void			ft_verif_launcher(t_env *env);

void			ft_roomsend(t_rooms **rooms, t_datas datas);
void			ft_pipesend(t_pipes **pipes, t_datas datas);
void			ft_set_env(t_env *env);

#endif
