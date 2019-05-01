# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 09:47:44 by ndombre           #+#    #+#              #
#    Updated: 2018/01/25 11:25:42 by ndombre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WORDIR=tmp
BUILDDIR=$(WORDIR)

NAME=libft.a

TESTDIR=tests

FLAG_ADD= #-fprofile-arcs -ftest-coverage -DLOVE # -Ofast -fsanitize=undefined -fsanitize=address

DEP=libft.h ft_printf/ft_printf.h btree.h get_next_line.h Makefile
SRCLIB=ft_strinc.c ft_artoi.c ft_atoi.c ft_bzero.c ft_free.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c ft_isxdigit.c ft_itoa.c ft_litoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_malloc.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c ft_memset.c ft_mitoa.c ft_mutoa_base.c ft_mutoa.c ft_mutoa_mbase.c ft_print_memory.c ft_putbasse.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_puterrl.c ft_puthex.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoinff.c ft_strjoinfn.c ft_strjoinnf.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strntest.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtest.c ft_strtrim.c ft_strwlen.c ft_time.c ft_tolower.c ft_toupper.c ft_wcstombs.c ft_wcstostr.c ft_wctoms.c ft_write.c ft_wtoc.c ft_wtoclen.c
SRCPRI=ft_printf.c ft_fprintf.c ft_printf_conversion.c ft_printf_flag.c ft_printf_incompatible_flag.c ft_printf_macro.c ft_printf_minlen.c ft_printf_modlen.c ft_printf_presition.c ft_printf_print.c ft_printf_r_forcenum.c ft_printf_r_numpre.c ft_printf_r_prefix.c ft_printf_r_str0mod.c ft_printf_r_strmod.c ft_printf_r_strpre.c ft_printf_r_strprefix.c ft_printf_spechar.c ft_print_time.c
SRCGNL=get_next_line_fd.c
SRCTRE=equi2.c equi.c find.c foreach.c free.c insert.c make.c
SRCLIS=ft_blist_add.c ft_blist_data.c ft_blist_dell.c ft_blist_iter.c ft_blist_new.c

SRC=$(addprefix libft/,$(SRCLIB)) \
	$(addprefix ft_printf/,$(SRCPRI)) \
	$(addprefix get_next_line/,$(SRCGNL)) \
	$(addprefix btree/,$(SRCTRE)) \
	$(addprefix blist/,$(SRCLIS))

OBJ=$(addprefix $(BUILDDIR)/obj/,$(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(DEP)
	ar rc $@ $^
	ranlib $@

$(BUILDDIR)/obj/%.o: %.c $(DEP)
	@mkdir -p $(dir $@)
	gcc $(FLAG_ADD) -Wall -Werror -Wextra -I. -I./libunit/ -o $@ -c $<

test: all
	(cd $(TESTDIR)/ && ./test.sh $(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
	diff $(TESTDIR)/ref.txt $(TESTDIR)/get.txt

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(BUILDDIR) || true

re: fclean
	make
