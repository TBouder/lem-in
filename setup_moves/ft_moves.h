/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:10:56 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 14:46:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MOVES_H
# define FT_MOVES_H

# include "../ft_lemin.h"

ULL		*ft_init_tab(ULL ant);
void	ft_print_moves(t_env *env, ULL *nbr, char **str);
void	ft_free_tr(t_env *env, char ***str);

int		*ft_init_mult_tab(int ant, int len);
void	ft_print_mult_moves(t_env *env, int *nbr, char ***str);

void	ft_display_move(int ant_id, char *room_name);
void	ft_display(t_env *env, int ant_id, char *room_name, int color);
int		ft_path_len(t_path *path);

int		***ft_init_trplnbr(t_path *origin);
void	ft_free_trplnbr(t_path *origin, int ***nbr);

#endif
