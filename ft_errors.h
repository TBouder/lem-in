/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:30:10 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 16:43:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define ERR00 "File {9}error{0} : arg must be a file"
# define ERR01 "File {9}error{0} : malloc error"
# define ERR02 "Room {9}error{0} : multiple start room"
# define ERR03 "Room {9}error{0} : multiple end room"
# define ERR04 "Map {9}error{0} : same room / coo"
# define ERR05 "Map {9}error{0} : start or end room not well formated"
# define ERR06 "Map {9}error{0} : pipe not well formated"
# define ERR07 "Map {9}error{0} : room not well formated"
# define ERR08 "Map {9}error{0} : map not well formated"
# define ERR09 "Coo {9}error{0} : not a number"
# define ERR10 "Ant {9}error{0} : must be > 0 && < 2147483648"
# define ERR11 "Map {9}error{0} : empty line"
# define ERR12 "Room {9}error{0} : room name cannot start with 'L'"
# define ERR13 "Room {9}error{0} : no start room"
# define ERR14 "Room {9}error{0} : no end room"
# define ERR15 "Room {9}error{0} : no path start"
# define ERR16 "Room {9}error{0} : no access end"
# define ERR17 "Pipe {9}error{0} : no pipe"
# define ERR18 "Pipe {9}error{0} : no room for this pipe"

#endif
