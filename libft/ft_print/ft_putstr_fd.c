/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:48 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/24 12:48:04 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr_fd() function prints the string str to the output stream
** pointed to by fd.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putstr_fd(char const *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}
