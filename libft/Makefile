# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/09/13 09:29:01 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra
OCLINT		=	oclint
OFLAGS		=	-enable-global-analysis -rc SHORT_VARIABLE_NAME=1 \
				-rc LONG_LINE=80 -rc CYCLOMATIC_COMPLEXITY=25 -disable-rule \
				UselessParentheses -disable-rule ParameterReassignment
HEADER 		= 	libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h

################################################################################
#	LIBFT
################################################################################
FT_IS		= 	$(wildcard ft_is/*.c)
FT_LEN		= 	$(wildcard ft_len/*.c)
FT_LST		= 	$(wildcard ft_lst/*.c)
FT_MEM		= 	$(wildcard ft_mem/*.c)
FT_NB		= 	$(wildcard ft_nb/*.c)
FT_PRINT	= 	$(wildcard ft_print/*.c)
FT_STR		= 	$(wildcard ft_str/*.c)
FT_DBSTR	= 	$(wildcard ft_dbstr/*.c)
FT_MATH		= 	$(wildcard ft_math/*.c)
FT_HASH		= 	$(wildcard ft_hash/*.c)
LIBFT		=	$(FT_IS) $(FT_LEN) $(FT_LST) $(FT_MEM) $(FT_NB) $(FT_PRINT) \
				$(FT_STR) $(FT_DBSTR) $(FT_MATH) $(FT_HASH)

################################################################################
#	GET_NEXT_LINE
################################################################################
GET			= 	$(filter-out get_next_line/main_test.c, \
				$(wildcard get_next_line/*.c))
GNL			=	$(GET)

################################################################################
#	FT_PRINTF
################################################################################
PRINTF		= 	$(filter-out ft_printf/main_test.c, \
				$(wildcard ft_printf/*.c))
PRINTF_CONV	= 	$(wildcard ft_printf/ft_conv/*.c)
PRINTF_FUNC	= 	$(wildcard ft_printf/ft_funcs/*.c)
PRINTF_COL	= 	$(wildcard ft_printf/ft_colors/*.c)
FT_PRINTF	=	$(PRINTF) $(PRINTF_CONV) $(PRINTF_FUNC) $(PRINTF_COL)

SRC			=	$(LIBFT) $(GET) $(FT_PRINTF)
OBJ			=	$(notdir $(SRC:.c=.o))
JUNCK		=	$(wildcard .DS_Store */.DS_Store */*/.DS_Store *.gch \
				get_next_line/*.gch ft_printf/*.gch)


################################################################################
#	RULES
################################################################################
.SILENT : $(NAME) clean fclean oclint

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(JUNCK)

fclean: clean
	rm -f $(NAME)

re: fclean all

list:
	ar t $(NAME)

oclint:
	$(OCLINT) $(OFLAGS) $(LIBFT) $(GET) $(FT_PRINTF) $(HEADER) -- c
