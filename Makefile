# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/22 12:12:36 by tbouder           #+#    #+#              #
#    Updated: 2016/05/04 22:32:16 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	lem-in

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra
OPTI		=	-g -O3

SRC 		= 	ft_lemin.c ft_tools.c ft_structs.c ft_structs_two.c ft_extract.c ft_extract_pipes.c \
				ft_verifs.c ft_verifs_duplicates.c ft_free.c ft_algo.c ft_print.c \
				ft_find_specific_room.c ft_find_path.c ft_progress.c ft_clr_deadend.c

LIB			=	-Lft_printf -lftprintf

OBJ			=	$(SRC:.c=.o)

HEADER 		=	ft_lemin.h ft_printf/ft_printf.h

all: $(NAME)

.SILENT : $(NAME) $(OBJ)
$(NAME): $(OBJ)
	# $(MAKE) re -C ft_printf
	$(CC) $(CFLAGS) $(OPTI) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	# $(MAKE) clean -C ft_printf
	rm -f $(OBJ)
	rm -f **/*.gch
	rm -rf *.dSYM

.SILENT : fclean
fclean: clean
	# $(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
