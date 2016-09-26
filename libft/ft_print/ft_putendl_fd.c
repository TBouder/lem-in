/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:33:45 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/24 12:47:34 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl_fd() function prints the string str to the output stream
** pointed to by fd followed by a \n.
*/

#include "../libft.h"

void		ft_putendl_fd(char const *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
