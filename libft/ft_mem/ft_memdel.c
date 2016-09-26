/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:30:56 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:10:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memdel() function deallocates the memory allocation pointed to by ap
** and set ap to NULL. If ap is a NULL pointer, no operation is performed.
*/

#include "../libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
