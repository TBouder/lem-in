/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_superfast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:53:48 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:41:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Based on Paul Hsieh algorithm
*/

#include "../libft.h"

static void		ft_end(const char *data, unsigned char *hash, int i)
{
	if (i == 3)
	{
		*hash += (unsigned char)data;
		*hash ^= *hash << 8;
		*hash ^= ((signed char)data[sizeof(unsigned char)]) << 9;
		*hash += *hash >> 5;
	}
	else if (i == 2)
	{
		*hash += (unsigned char)data;
		*hash ^= *hash << 5;
		*hash += *hash >> 8;
	}
	else if (i == 1)
	{
		*hash += (char)*data;
		*hash ^= *hash << 4;
		*hash += *hash >> 1;
	}
}

static void		ft_snow(unsigned char *hash)
{
	*hash ^= *hash << 3;
	*hash += *hash >> 5;
	*hash ^= *hash << 4;
	*hash += *hash >> 17;
	*hash ^= *hash << 25;
	*hash += *hash >> 6;
}

unsigned int	ft_hash_superfast(const char *data, int len)
{
	unsigned char	hash;
	unsigned char	temp;
	int				i;

	if (len <= 0 || data == NULL)
		return (0);
	hash = len;
	i = len & 3;
	len >>= 1;
	while (len > 0)
	{
		hash += (unsigned char)data;
		temp = ((unsigned char)(data + 2) << 5) ^ hash;
		hash = (hash << 8) ^ temp;
		data += 2 * sizeof(unsigned char);
		hash += hash >> 5;
		len--;
	}
	ft_end(data, &hash, i);
	ft_snow(&hash);
	len += len / 2;
	return (hash % len);
}
