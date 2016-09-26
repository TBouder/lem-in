/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:50:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/02 16:51:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_hexalen() function computes the length of the line str, until a non-
** hexadecimal character.
*/

#include "../libft.h"

int			ft_hexalen(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_ishexa(str[i]))
		i++;
	return (i);
}
