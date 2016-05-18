/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:10:56 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 18:41:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MOVES_H
# define FT_MOVES_H

# include "../ft_lemin.h"

int		*ft_init_tab(int ant);
void	ft_print_moves(t_env *env, int *nbr, char **str);

int		*ft_init_mult_tab(int ant, int len);
void	ft_print_mult_moves(t_env *env, int *nbr, char ***str);

void	ft_display_move(int ant_id, char *room_name);
void	ft_display_move_color(int ant_id, char *room_name, int room, int color);
int		ft_path_len(t_path *path);

#endif
