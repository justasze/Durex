/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:07:30 by ndombre           #+#    #+#             */
/*   Updated: 2016/12/09 11:41:13 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLIST_H
# define BLIST_H

# include "libft.h"

struct				s_blist_elem
{
	struct s_blist_elem	*next;
};

struct				s_blist
{
	int					list_type;
	struct s_blist_elem	*next;
	size_t				content_size;
};

struct s_blist		*ft_blist_new(size_t content_size);
struct s_blist		ft_blist_ini(size_t content_size);
struct s_blist_elem	*ft_blist_new_elem(struct s_blist *list,
		void const *data);

struct s_blist_elem	*ft_blist_add_first_elem(struct s_blist *l,
		void const *data);
struct s_blist_elem	*ft_blist_add_last_elem(struct s_blist *l,
		void const *data);

void				ft_blist_del_all(struct s_blist *dl);
void				ft_blist_del_feast(struct s_blist *dl);

void				ft_blist_iter(struct s_blist *dl, void (*f)(void *d));
void				ft_blist_iteri(struct s_blist *dl,
		void (*f)(void *d, size_t i));
void				*ft_blist_find(struct s_blist *dl, int (*f)(void *d,
			void *query), void *query);

void				*ft_blist_data(struct s_blist_elem *elem);

#endif
