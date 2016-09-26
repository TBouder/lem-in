/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:35:40 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:31:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strclr() function clear the string s by replacing each char by \0.
*/

#include "../libft.h"

void		ft_strclr(char *s)
{
	if (s != NULL)
		ft_bzero(s, ft_strlen(s));
}
