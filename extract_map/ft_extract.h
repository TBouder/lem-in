/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:42:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 16:23:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXTRACT_H
# define FT_EXTRACT_H

# include "../ft_lemin.h"

typedef struct	s_datas
{
	char		*name;
	char		*name_two;
	int			x;
	int			y;
	int			id;
	int			pos;
}				t_datas;

typedef struct	s_flg
{
	int			f_soft;
	int			f_path;
	int			f_color;
	int			f_dist;
	int			f_info;
	int			nb;
}				t_flg;

void			ft_extract(int ac, char **av, t_env **env);

/*
**Ft_get_parts
*/
void			ft_get_map(t_env *env);
void			ft_get_ant(t_env *env);
void			ft_get_diaiz(t_env *env, int *lines);
void			ft_get_room(t_env *env, int *lines);
int				ft_get_pipe(t_env *env, int v);

/*
**Ft_extract_flg
*/
void			ft_set_flg(t_env *env, t_flg flg);
void			ft_init_flg(t_flg *flg);
int				ft_extract_flg(char **str, t_flg *flg, int i, int j);

/*
**Ft_extract_tools
*/
void			ft_more(int ac, char **av, t_env **env, t_flg *flg);
void			ft_put_map(t_env *env, char *str);
char			*ft_join(char **s);
t_hroom			*ft_find_elem(t_hroom *base, char *data);
int				ft_check_if_already_exist(t_env *env, int hash[2], char **s);

/*
**Ft_extract_struct
*/
void			ft_hroomend(t_env *env, t_hroom **hlist, char *str, char **s);
void			ft_hpipesend(t_hpipe **hlist, t_hroom *str);
void			ft_hcooend(t_hroom **hlist, char **s);

/*
**Ft_extract_init
*/
void			ft_init_env(t_env *env);
void			ft_malloc_env(t_env *env, int *lines);

#endif
