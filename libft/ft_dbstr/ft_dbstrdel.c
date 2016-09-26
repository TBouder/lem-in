/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:52:38 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/02 14:55:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_dbstrdel() function desallocs **str
*/

#include "../libft.h"
#include <stdlib.h>

void		ft_dbstrdel(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}
