/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:31:48 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/21 22:13:05 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putchar() function writes the character c (converted to an
** 'unsigned char') to STDIN.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
