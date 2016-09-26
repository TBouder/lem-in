/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/24 12:47:20 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl() function prints the string str to STDIN followed by a \n.
*/

#include "../libft.h"

void		ft_putendl(char const *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
