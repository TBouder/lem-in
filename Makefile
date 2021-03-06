# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/22 12:12:36 by tbouder           #+#    #+#              #
#    Updated: 2016/09/26 15:18:39 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	lem-in

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g
OPTI		=	-g -O3 -O2

EXTRACT		=	$(wildcard extract_map/*.c)
FIND		=	$(wildcard find_path/*.c)
MOVES		=	$(wildcard setup_moves/*.c)
SHARED		=	$(wildcard ./*.c)
SRC			=	$(EXTRACT) $(FIND) $(MOVES) $(SHARED)
HEAD		=	ft_lemin.h ft_errors.h extract_map/ft_extract.h find_path/ft_find.h setup_moves/ft_moves.h

# LIB			=	-Lft_printf -lftprintf
LIB			=	libft/libft.a

OBJ			=	$(patsubst %.c,%.o, $(SRC))

JUNCK		=	$(wildcard *.gch */*.gch .DS_Store */.DS_Store)
DIRJUNCK	=	lem-in.dSYM


all: $(NAME)

.SILENT : $(NAME) $(OBJ)
$(NAME): $(OBJ) $(HEAD)
	$(MAKE) re -C libft
	$(CC) $(CFLAGS) $(OPTI) -c $(SRC)
	$(CC) -o $@ $(OBJ) $(LIB)

.SILENT : clean
clean:
	$(MAKE) clean -C libft
	rm -f $(notdir $(OBJ)) $(OBJ) $(JUNCK)
	rm -rf $(DIRJUNCK)

.SILENT : fclean
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all
