/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:25:30 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/20 16:34:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isprint() function tests for any printing character,
** including space (` ').
*/

#include "../libft.h"

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
