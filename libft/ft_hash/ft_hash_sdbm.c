/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_sdbm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 01:02:34 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:40:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sdbm hash algo, 10724/20000 ~
*/

#include "../libft.h"

unsigned int	ft_hash_sdbm(char *str, int len)
{
	unsigned int	hash;
	int				counter;

	hash = 0;
	counter = 0;
	while (str[counter])
	{
		hash = str[counter] + (hash << 6) + (hash << 16) - hash;
		counter++;
	}
	len += len / 2;
	return (hash % len);
}
