/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/22 12:28:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois
** - Lecture entree standard
*/

void	ft_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*str;

	i = 1;
	if (ac == 1)
	{
		while (get_next_line(0, &str)) //REFAIRE GET NEXT LINE
			ft_putstr(str);
	}

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ft_exit("Opening error : wrong map");
		else
			ft_putnbr(fd);

	}

	if (ac > 2)
	{
		while (i < ac)
		{
			if ((fd = open(av[i], O_RDONLY)) == -1)
				ft_exit("Opening error : wrong map");
			else
				ft_putnbr(fd);
			i++;
		}
	}
	return (0);
}
