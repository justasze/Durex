# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndombre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 00:00:12 by ndombre           #+#    #+#              #
#    Updated: 2019/05/01 18:27:44 by ndombre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TMP = tmp/

SRC = durex_deamon.c main.c
OBJ = $(addprefix $(TMP), $(SRC:.c=.o))

SRC_DEAMON = main_deamon.c
OBJ_DEAMON = $(addprefix $(TMP), $(SRC_DEAMON:.c=.o))

DEP = $(OBJ:.o=.d) $(OBJ_DEMON:.o=.d)

NAME = Durex
NAME_DEAMON = $(TMP)/durex_deamon

CFLAGS = 

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	gcc -Wall -Werror -Wextra -o $@ $^

$(NAME_DEAMON): $(OBJ_DEAMON) libft/libft.a
	gcc -Wall -Werror -Wextra -o $@ $^

$(TMP)durex_deamon.c: $(NAME_DEAMON)
	(cd $(TMP) ; xxd -i durex_deamon durex_deamon.c)

$(TMP)durex_deamon.o: $(TMP)durex_deamon.c | $(TMP)
	gcc -Wall -Werror -Wextra -I includes -I libft -MD -c -o $@ $<

$(TMP)%.o: srcs/%.c | $(TMP)
	gcc -Wall -Werror -Wextra -I includes -I libft -MD -c -o $@ $<

libft/libft.a: libft/libft libft/blist libft/btree libft/ft_printf libft/get_next_line libft
	make -C libft

$(TMP):
	mkdir -p $(TMP)

-include $(DEP)

clean:
	rm $(OBJ) || true
	rm $(OBJ_DEMON) || true
	rm $(DEP) || true
	rm $(BIN_DEMON) || true
	rm -r $(TMP)
	make fclean -C libft
	rm -rf $(NAME).dSYM || true
	rm -rf $(NAME_DEMON).dSYM || true

fclean: clean
	rm $(NAME) || true

re: fclean
	make

test: all
	echo "no test for now"

.PHONY: re fclean clean all test
