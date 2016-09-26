/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_djbtwo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 01:05:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:40:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dbj2 hash algo, 4433/20000 ~
*/

#include "../libft.h"

unsigned int	ft_hash_djbtwo(char *str, int len)
{
	unsigned int	hash;
	int				counter;

	hash = 5381;
	counter = 0;
	while (str[counter])
	{
		hash = ((hash << 5) + hash) + str[counter];
		counter++;
	}
	len += len / 2;
	return (hash % len);
}
