/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:31:19 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/26 16:30:40 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# define BTREE_REEQUI 5

struct					s_bnode
{
	unsigned int		nbnode;
	struct s_bnode		*left;
	struct s_bnode		*right;
	char				opti;
	void				*data;
};

struct					s_btree
{
	struct s_bnode		*node;
	int					(*cmp)(void*, void*);
	int					(*free)(void*, void*);
	unsigned int		maxnode;
	unsigned int		curantnode;
	unsigned int		reequi;
};

struct s_bnode			*btree_node_make(void *data);
struct s_btree			*btree_make(int (*cmp)(void*, void*),
		int (*free)(void*, void*), unsigned int maxnode);

void					*btree_find(struct s_btree *btree, void *data);
void					btree_foreach_croi(struct s_bnode *node,
		void (*fonc)(void*, void*), void *a);

void					btree_equilibre_setnbnode(struct s_bnode *node);
int						btree_equilibre(struct s_bnode *node,
		struct s_bnode *nodep);
void					equi(struct s_bnode *n);
int						btree_insert(struct s_btree *btree, void *data);

void					freebtree(struct s_btree *btree,
		struct s_bnode *n, void *cmp);

#endif
