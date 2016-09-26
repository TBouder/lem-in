/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 01:27:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/21 01:27:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dbj2 hash algo, 4433/20000 ~
*/

#include "../libft.h"

unsigned int	ft_hash_little(char *str, int len)
{
	unsigned int	hash;
	int				counter;

	hash = 5381;
	counter = 0;
	len += len / 2;
	while (str[counter])
	{
		hash = (11 * hash + str[counter]) % len;
		counter++;
	}
	return (hash);
}
