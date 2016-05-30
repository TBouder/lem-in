/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:46:11 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 17:16:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

int		***ft_init_trplnbr(t_path *origin)
{
	int		j;
	int		k;
	int		len;
	int		***nbr;
	t_path	*path;

	path = origin;
	!(nbr = (int ***)malloc(sizeof(int **) * ft_path_len(path))) ? exit(1) : 0;
	j = 0;
	while (path)
	{
		len = ft_strcountchar(path->path, ' ');
		!(nbr[j] = (int **)malloc(sizeof(int *) * len)) ? exit(1) : 0;
		k = 0;
		while (k < len)
		{
			nbr[j][k] = ft_nbrnew(2);
			k++;
		}
		j++;
		path = path->next;
	}
	return (nbr);
}

void	ft_free_trplnbr(t_path *origin, int ***nbr)
{
	int		j;
	int		k;
	int		len;
	t_path	*path;

	path = origin;
	j = 0;
	while (path)
	{
		len = ft_strcountchar(path->path, ' ');
		ft_strstr(path->path, "LERR") ? len-- : 0;
		k = 0;
		while (k < len)
			free(nbr[j][k++]);
		free(nbr[j]);
		j++;
		path = path->next;
	}
	free(nbr);
}
