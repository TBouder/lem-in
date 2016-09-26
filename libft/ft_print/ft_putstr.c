/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/24 12:47:49 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr() function prints the string str to STDIN.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
