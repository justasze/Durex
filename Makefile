# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: justasze <justasze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 00:00:12 by ndombre           #+#    #+#              #
#    Updated: 2019/05/08 17:18:26 by justasze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TMP = tmp/

SRC = durex_daemon.c main.c durex_init.c
OBJ = $(addprefix $(TMP), $(SRC:.c=.o))

SRC_DAEMON = main_daemon.c server_loop.c client_read.c sha512.c
OBJ_DAEMON = $(addprefix $(TMP), $(SRC_DAEMON:.c=.o))

DEP = $(OBJ:.o=.d) $(OBJ_DEMON:.o=.d)

NAME = Durex
NAME_DAEMON = $(TMP)/durex_daemon

CFLAGS = 

all: $(NAME)

install: $(NAME)
	kill `pgrep Durex` 2> /dev/null || true
	./$(NAME)

$(NAME): $(OBJ) libft/libft.a
	gcc -Wall -Werror -Wextra -o $@ $^

$(NAME_DAEMON): $(OBJ_DAEMON) libft/libft.a
	gcc -Wall -Werror -Wextra -o $@ $^

$(TMP)durex_daemon.c: $(NAME_DAEMON)
	(cd $(TMP) ; xxd -i durex_daemon durex_daemon.c)

$(TMP)durex_daemon.o: $(TMP)durex_daemon.c | $(TMP)
	gcc -Wall -Werror -Wextra -I includes -I libft -MD -c -o $@ $<

$(TMP)durex_init.c: Durex.init
	xxd -i $< $@

$(TMP)durex_init.o: $(TMP)durex_init.c | $(TMP)
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
