/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:36:23 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:35:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strdel() function is identical to ft_memdel(), except it works for
** strings and not voids.
*/

#include "../libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
