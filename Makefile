# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/22 12:12:36 by tbouder           #+#    #+#              #
#    Updated: 2016/05/10 23:58:30 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	lem-in

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra
OPTI		=	-g -O3


EXTRACT		=	$(wildcard extract_map/*.c)
FIND		=	$(wildcard find_path/*.c)
MOVES		=	$(wildcard setup_moves/*.c)
SHARED		=	main.c ft_tools.c ft_free.c ft_print.c ft_find_specific_room.c
SRC			=	$(EXTRACT) $(FIND) $(MOVES) $(notdir $(SHARED))

LIB			=	-Lft_printf -lftprintf

OBJ			=	$(patsubst %.c,%.o, $(SRC))

JUNCK		=	$(wildcard *.gch */*.gch .DS_Store */.DS_Store)


all: $(NAME)

.SILENT : $(NAME) $(OBJ)
$(NAME): $(OBJ)
	# $(MAKE) re -C ft_printf
	$(CC) $(CFLAGS) $(OPTI) -o $@ $(OBJ) $(LIB)
	# $(CC) -o $@ $(OBJ) $(LIB)

.SILENT : clean
clean:
	# $(MAKE) clean -C ft_printf
	rm -f $(OBJ) $(JUNCK)

.SILENT : fclean
fclean: clean
	# $(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
