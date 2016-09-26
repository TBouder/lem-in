/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:50:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/02 14:51:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_dbstrlen() function computes the length of **str.
*/

#include "../libft.h"

int		ft_dbstrlen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
