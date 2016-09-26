/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:21:09 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:42:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print the memory of addr
*/

#include "../libft.h"

static void		ft_print_raw_mem(char *add, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (add[i] >= 32 && add[i] < 127)
			ft_putchar(add[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

static void		ft_print_hex_mem(char *add, size_t size)
{
	size_t		i;
	char		*hex;

	hex = ft_strinit("0123456789abcdef");
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_putchar(hex[(int)((unsigned char)add[i]) / 16]);
			ft_putchar(hex[(int)((unsigned char)add[i]) % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	ft_strdel(&hex);
}

void			ft_print_memory(const void *addr, size_t size)
{
	int		offset;

	offset = 0;
	while (size > 16)
	{
		ft_print_hex_mem((char *)addr + offset, 16);
		ft_print_raw_mem((char *)addr + offset, 16);
		offset += 16;
		size -= 16;
	}
	ft_print_hex_mem((char *)addr + offset, size);
	ft_print_raw_mem((char *)addr + offset, size);
}
